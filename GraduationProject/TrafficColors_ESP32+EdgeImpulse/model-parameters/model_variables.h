/*
 * Copyright (c) 2024 EdgeImpulse Inc.
 *
 * Generated by Edge Impulse and licensed under the applicable Edge Impulse
 * Terms of Service. Community and Professional Terms of Service
 * (https://docs.edgeimpulse.com/page/terms-of-service) or Enterprise Terms of
 * Service (https://docs.edgeimpulse.com/page/enterprise-terms-of-service),
 * according to your product plan subscription (the “License”).
 *
 * This software, documentation and other associated files (collectively referred
 * to as the “Software”) is a single SDK variation generated by the Edge Impulse
 * platform and requires an active paid Edge Impulse subscription to use this
 * Software for any purpose.
 *
 * You may NOT use this Software unless you have an active Edge Impulse subscription
 * that meets the eligibility requirements for the applicable License, subject to
 * your full and continued compliance with the terms and conditions of the License,
 * including without limitation any usage restrictions under the applicable License.
 *
 * If you do not have an active Edge Impulse product plan subscription, or if use
 * of this Software exceeds the usage limitations of your Edge Impulse product plan
 * subscription, you are not permitted to use this Software and must immediately
 * delete and erase all copies of this Software within your control or possession.
 * Edge Impulse reserves all rights and remedies available to enforce its rights.
 *
 * Unless required by applicable law or agreed to in writing, the Software is
 * distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific language governing
 * permissions, disclaimers and limitations under the License.
 */

#ifndef _EI_CLASSIFIER_MODEL_VARIABLES_H_
#define _EI_CLASSIFIER_MODEL_VARIABLES_H_

/**
 * @file
 *  Auto-generated complete impulse definitions. The ei_impulse_handle_t should
 *  be passed to ei_run_classifier() function to use this specific impulse.
 *  This file should only be included in ei_run_classifier.h file.
 */

#include <stdint.h>
#include "model_metadata.h"

#include "tflite-model/tflite_learn_3_compiled.h"
#include "edge-impulse-sdk/classifier/ei_model_types.h"
#include "edge-impulse-sdk/classifier/inferencing_engines/engines.h"

const char* ei_classifier_inferencing_categories[] = { "Traffic-Green", "Traffic-Red", "Traffic-Yellow" };

ei_dsp_named_axis_t ei_dsp_config_2_named_axes[] = {
    { .name = "Image", .axis = 0 }
};
size_t ei_dsp_config_2_named_axes_size = 1;
uint8_t ei_dsp_config_2_axes[] = { 0 };
const uint32_t ei_dsp_config_2_axes_size = 1;
ei_dsp_config_image_t ei_dsp_config_2 = {
    2, // uint32_t blockId
    1, // int implementationVersion
    1, // int length of axes
    ei_dsp_config_2_named_axes, // named axes
    ei_dsp_config_2_named_axes_size, // size of the named axes array
    "RGB" // select channels
};

const uint8_t ei_dsp_blocks_size = 1;
ei_model_dsp_t ei_dsp_blocks[ei_dsp_blocks_size] = {
    { // DSP block 2
        2,
        27648, // output size
        &extract_image_features, // DSP function pointer
        (void*)&ei_dsp_config_2, // pointer to config struct
        ei_dsp_config_2_axes, // array of offsets into the input stream, one for each axis
        ei_dsp_config_2_axes_size, // number of axes
        1, // version
        nullptr, // factory function
    }
};
const ei_config_tflite_eon_graph_t ei_config_tflite_graph_3 = {
    .implementation_version = 1,
    .model_init = &tflite_learn_3_init,
    .model_invoke = &tflite_learn_3_invoke,
    .model_reset = &tflite_learn_3_reset,
    .model_input = &tflite_learn_3_input,
    .model_output = &tflite_learn_3_output,
};

const ei_learning_block_config_tflite_graph_t ei_learning_block_config_3 = {
    .implementation_version = 1,
    .classification_mode = EI_CLASSIFIER_CLASSIFICATION_MODE_OBJECT_DETECTION,
    .block_id = 3,
    .object_detection = 1,
    .object_detection_last_layer = EI_CLASSIFIER_LAST_LAYER_FOMO,
    .output_data_tensor = 0,
    .output_labels_tensor = 1,
    .output_score_tensor = 2,
    .threshold = 0.5,
    .quantized = 1,
    .compiled = 1,
    .graph_config = (void*)&ei_config_tflite_graph_3
};

const uint8_t ei_learning_blocks_size = 1;
const uint32_t ei_learning_block_3_inputs[1] = { 2 };
const uint8_t ei_learning_block_3_inputs_size = 1;
const ei_learning_block_t ei_learning_blocks[ei_learning_blocks_size] = {
    {
        3,
        false,
        &run_nn_inference,
        (void*)&ei_learning_block_config_3,
        EI_CLASSIFIER_IMAGE_SCALING_NONE,
        ei_learning_block_3_inputs,
        ei_learning_block_3_inputs_size,
        576
    },
};


const ei_object_detection_nms_config_t ei_object_detection_nms = {
    0.0f, /* NMS confidence threshold */
    0.2f  /* NMS IOU threshold */
};

const ei_impulse_t impulse_563333_0 = {
    .project_id = 563333,
    .project_owner = "Amal Alkraimeen",
    .project_name = "Traffic Lights",
    .impulse_id = 1,
    .impulse_name = "Impulse #1",
    .deploy_version = 3,

    .nn_input_frame_size = 27648,
    .raw_sample_count = 9216,
    .raw_samples_per_frame = 1,
    .dsp_input_frame_size = 9216 * 1,
    .input_width = 96,
    .input_height = 96,
    .input_frames = 1,
    .interval_ms = 1,
    .frequency = 0,
    .dsp_blocks_size = ei_dsp_blocks_size,
    .dsp_blocks = ei_dsp_blocks,
    
    .object_detection_count = 10,
    .fomo_output_size = 12,
    
    
    .visual_ad_grid_size_x = int((96 / 8) / 2 - 1),
    .visual_ad_grid_size_y = int((96 / 8) / 2 - 1),
    
    .tflite_output_features_count = 576,
    .learning_blocks_size = ei_learning_blocks_size,
    .learning_blocks = ei_learning_blocks,

    .postprocessing_blocks_size = 0,
    .postprocessing_blocks = nullptr,

    .inferencing_engine = EI_CLASSIFIER_TFLITE,

    .sensor = EI_CLASSIFIER_SENSOR_CAMERA,
    .fusion_string = "image",
    .slice_size = (9216/4),
    .slices_per_model_window = 4,

    .has_anomaly = EI_ANOMALY_TYPE_UNKNOWN,
    .label_count = 3,
    .categories = ei_classifier_inferencing_categories,
    .object_detection_nms = ei_object_detection_nms
};

ei_impulse_handle_t impulse_handle_563333_0 = ei_impulse_handle_t( &impulse_563333_0 );
ei_impulse_handle_t& ei_default_impulse = impulse_handle_563333_0;

#endif // _EI_CLASSIFIER_MODEL_VARIABLES_H_
