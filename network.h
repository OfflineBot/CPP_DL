#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <random>
#include <cmath>

#include "structs/norm_struct.h"
#include "structs/matrix_struct.h"
#include "structs/learning_struct.h"

using namespace std;

template<typename T>
using vec1 = vector<T>;
template<typename T>
using vec2 = vector<vec1<T>>;
template<typename T>
using vec3 = vector<vec2<T>>;


class DL {
private:

    vec1<float> mean(vec2<float> array);
    vec1<float> std(vec2<float> array);
    vec2<float> norm(vec2<float> array, vec1<float> input_mean, vec1<float> input_std);

    vec1<float> random_array(int cols);
    vec2<float> random_array(int rows, int cols);
    vec3<float> random_array(int items, int rows, int cols);

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

    Matrix init_matrix(Dimension dim) {

        vec2<float> w1 = random_array(dim.input_layer_size, dim.hidden_layer_size);
        vec1<float> b1 = random_array(dim.hidden_layer_size);
        vec3<float> w = random_array(dim.hidden_layers, dim.hidden_layer_size, dim.hidden_layer_size);
        vec2<float> b = random_array(dim.hidden_layers, dim.hidden_layer_size);
        vec2<float> w2 = random_array(dim.hidden_layer_size, dim.output_layer_size);
        vec1<float> b2 = random_array(dim.output_layer_size);

        Matrix my_matrix = Matrix {
                w1,
                b1,
                w,
                b,
                w2,
                b2, 
        };
        return my_matrix;
    }

    TrainingData training(int iterations, float learning_rate, Dimension dim, Matrix matrix, Normalize norm) {

        for (int iter = 0; iter <= iterations; iter++) {
            if (iter % 1000 == 0) {
                printf("%f%", round(iter / iterations * 100.0f));
            }
        }
    }

};

#endif