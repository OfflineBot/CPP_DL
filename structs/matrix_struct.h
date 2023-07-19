#include "../network.h"

typedef struct {
    vec2<float> w1;
    vec1<float> b1;
    vec3<float> w;
    vec2<float> b;
    vec2<float> w2;
    vec1<float> b2;
} Matrix;

typedef struct {
    int input_layer_size;
    int hidden_layer_size;
    int output_layer_size;
    int hidden_layers;
} Dimension;