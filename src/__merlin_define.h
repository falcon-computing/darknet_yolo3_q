#ifdef __cplusplus
extern "C" {
#endif
typedef int8_t DATA_T;
extern int __merlin_init(const char * bitstream);
extern int __merlin_release();
extern int __merlin_exec_top_kernel_overlap(DATA_T * input,
        DATA_T * yolo1_pre_layer, DATA_T * yolo2_pre_layer, DATA_T * yolo3_pre_layer,
        int * debug_config);
extern int __merlin_load_weight(DATA_T *weights[75], int32_t bias[75][1024]);
#ifdef __cplusplus
}
#endif
