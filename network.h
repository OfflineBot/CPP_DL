#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <random>
#include <cmath>


using namespace std;

template<typename T>
using vec1 = vector<T>;
template<typename T>
using vec2 = vector<vec1<T>>;
template<typename T>
using vec3 = vector<vec2<T>>;

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

typedef struct {
    vec2<float> w1;
    vec1<float> b1;
    vec3<float> w;
    vec2<float> b;
    vec2<float> w2;
    vec1<float> b2;
} Matrix;

class DL {
private:

    vec1<float> mean(vec2<float> array);
    vec1<float> std(vec2<float> array);
    vec2<float> norm(vec2<float> array, vec1<float> input_mean, vec1<float> input_std);

    vec1<float> zero_array1(int cols);
    vec2<float> zero_array2(int rows, int cols);
    vec3<float> zero_array3(int items, int rows, int cols);

public:

    Normalize normalize(vec2<float> input_array, vec2<float> output_array) { 

        vec1<float> input_mean = DL::mean(input_array);
        vec1<float> input_std = DL::std(input_array);
        vec2<float> input_norm = DL::norm(input_array, input_mean, input_std);

        vec1<float> output_mean = DL::mean(output_array);
        vec1<float> output_std = DL::std(output_array);
        vec2<float> output_norm = DL::norm(output_array, output_mean, output_std);

        Normalize data = Normalize {
            input_array,
            input_mean,
            input_std,
            input_norm,
            output_array,
            output_mean,
            output_std,
            output_norm,
        };
        return data;
    }

    Matrix init_matrix(int input_layer_size, int hidden_layer_size, int output_layer_size, int hidden_layers) {

    }

};

#endif