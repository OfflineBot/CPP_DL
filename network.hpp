#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <random>
#include <cmath>

#include "types/vec_type.hpp"
#include "structs/norm_struct.hpp"
#include "structs/matrix_struct.hpp"
#include "structs/learning_struct.hpp"


class DL {
private:

    // normalize
    vec1<float> mean(vec2<float> array);
    vec1<float> std(vec2<float> array);
    vec2<float> norm(vec2<float> array, vec1<float> input_mean, vec1<float> input_std);

    // fill array
    vec1<float> random_array(int cols);
    vec2<float> random_array(int rows, int cols);
    vec3<float> random_array(int items, int rows, int cols);

    // Forward + Backward + Update
    ZAStorage forward(Matrix matrix, Normalize norm);
    DeltaStorage backward(Matrix matrix, ZAStorage za_storage);
    Matrix update_matrix(Matrix matrix, ZAStorage za_storage, DeltaStorage delta_storage);

    // Sigmoid
    vec2<float> sigmoid(vec2<float> array);
    vec2<float> deriv_sigmoid(vec2<float> array);

    // Relu
    vec2<float> relu(vec2<float> array);
    vec2<float> deriv_relu(vec2<float> array);

    // Math
    vec2<float> dot(vec2<float> array1, vec2<float> array2);

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

            ZAStorage za_storage = forward(matrix, norm);
            DeltaStorage delta_storage = backward(matrix, za_storage);
            matrix = update_matrix(matrix, za_storage, delta_storage);
            
        }

        vec1<float> x_mean = norm.input_mean;
        vec1<float> x_std = norm.input_std;
        vec1<float> y_mean = norm.output_mean;
        vec1<float> y_std = norm.output_std; 
        TrainingNorm t_norm = TrainingNorm {
            x_mean,
            x_std,
            y_mean,
            y_std,
        };
        TrainingData final_data = TrainingData {
            matrix,
            t_norm,
            dim,
        };
        return final_data;
    }

};

#endif