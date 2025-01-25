import os
import uuid
import subprocess
from PIL import Image
import pyttsx3
from time import sleep
import pytesseract
import RPi.GPIO as GPIO
from threading import Thread

# Initialize Tesseract OCR
pytesseract.pytesseract.tesseract_cmd = "/usr/bin/tesseract"

# Directory to store captured images
IMAGES_PATH = 'images'

# GPIO setup
BUTTON_PIN = 18  # GPIO pin where the button is connected

# Ensure the images directory exists
if not os.path.exists(IMAGES_PATH):
    os.makedirs(IMAGES_PATH)

# Initialize the text-to-speech engine
tts_engine = pyttsx3.init()
tts_engine.setProperty('rate', 150)  # Set speech rate
tts_engine.setProperty('volume', 0.9)  # Set volume level

# Select a female voice
voices = tts_engine.getProperty('voices')
for voice in voices:
    if "female" in voice.name.lower():  # Adjust condition based on system's available voices
        tts_engine.setProperty('voice', voice.id)
        break


def speak_message(message):
    """
    Speak a given message using pyttsx3.
    """
    print(message)  # Log the message
    tts_engine.say(message)
    tts_engine.runAndWait()


def resize_image(image_path):
    """
    Resize the image to make OCR more efficient.
    """
    try:
        image = Image.open(image_path)
        resized_image = image.resize((800, 600), Image.Resampling.LANCZOS)
        resized_image.save(image_path)  # Overwrite the original image
        print(f"Image resized successfully: {image_path}")
    except Exception as e:
        print(f"Error resizing image: {e}")


def capture_image():
    """
    Capture an image using libcamera-still and return the image path.
    """
    img_name = os.path.join(IMAGES_PATH, f'image_{uuid.uuid1()}.jpg')
    try:
        speak_message("Capturing image now.")
        subprocess.run(['libcamera-still', '-o', img_name, '--nopreview'], check=True)
        speak_message("Image captured successfully.")
        print(f"Image captured: {img_name}")
        return img_name
    except subprocess.CalledProcessError:
        speak_message("Error: Unable to capture the image.")
        return None


def perform_ocr_and_speak(image_path):
    """
    Perform OCR on an image and convert the text to speech.
    """
    print(f"Starting OCR on image: {image_path}")
    try:
        # Resize image for better OCR performance
        resize_image(image_path)

        # Perform OCR using pytesseract
        text = pytesseract.image_to_string(image_path)
        print(f"OCR Result:\n{text}")

        # Speak the OCR result
        if text.strip():
            speak_message("Reading the captured text.")
            speak_message(text)
        else:
            speak_message("No readable text found in the image.")
    except Exception as e:
        print(f"Error during OCR or speech conversion: {e}")
        speak_message("Error processing the image.")


def start_button_listener():
    """
    Wait for a button press and execute the capture, OCR, and TTS process.
    """
    print("Setting up GPIO...")
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(BUTTON_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)

    print("Press the button to capture an image...")
    speak_message("Press the button to capture an image.")
    try:
        while True:
            if GPIO.input(BUTTON_PIN) == GPIO.LOW:  # Button pressed
                print("Button pressed! Capturing image...")
                speak_message("Button pressed. Processing your request.")

                # Run capture and OCR in a separate thread
                Thread(target=process_image_capture).start()

                sleep(0.3)  # Debounce delay
    except KeyboardInterrupt:
        print("\nExiting...")
        speak_message("Exiting the program. Goodbye!")
    finally:
        GPIO.cleanup()  # Clean up GPIO on exit


def process_image_capture():
    """
    Capture an image and process it for OCR and TTS.
    """
    img_path = capture_image()
    if img_path:
        perform_ocr_and_speak(img_path)
        os.remove(img_path)  # Clean up the image after processing


if name == "__main__":