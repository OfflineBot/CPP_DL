#include "../types/vec_type.hpp"
#include "../network.hpp"

typedef struct
{
    vec2<float> input;
    vec1<float> input_mean;
    vec1<float> input_std;
    vec2<float> input_norm;

    vec2<float> output;
    vec1<float> output_mean;
    vec1<float> output_std;
    vec2<float> output_norm;
} Normalize;