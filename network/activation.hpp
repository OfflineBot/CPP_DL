#include <cmath>
#include "../types/vec_type.hpp"
#include "../network.hpp"

vec2<float> DL::sigmoid(vec2<float> array) {
    int rows = array.size();
    int cols = array[0].size();
    vec2<float> sig;
    for (int row = 0; row < rows; row++) {
        vec1<float> array_slice;
        for (int col = 0; col < cols; col++) {
            float item = 1.0 / (1.0 + exp(-array[row][col]));
            array_slice.push_back(item);
        }
        sig.push_back(array_slice);
    }
    return sig;
}

vec2<float> DL::deriv_sigmoid(vec2<float> array) {
    vec2<float> sig = DL::sigmoid(array);
    int rows = array.size();
    int cols = array[0].size();
    vec2<float> deriv_sig;
    for (int row = 0; row < rows; row++) {
        vec1<float> array_slice;
        for (int col = 0; col < cols; col++) {
            float item = sig[row][col] * (1.0 - sig[row][col]);
            array_slice.push_back(item);
        }
        deriv_sig.push_back(array_slice);
    }
    return deriv_sig;
}


vec2<float> DL::relu(vec2<float> array) {
    int rows = array.size();
    int cols = array[0].size();

    vec2<float> my_relu;

    for (int row = 0; row < rows; row++) {
        vec1<float> array_slice;
        for (int col = 0; col < cols; col++) {
            float item = array[row][col] < 0.0 ? 0.0f : array[row][col];
            array_slice.push_back(item);
        }
        my_relu.push_back(array_slice);
    }

    return my_relu;
}

vec2<float> DL::deriv_relu(vec2<float> array) {
    int rows = array.size();
    int cols = array[0].size();
    vec2<float> deriv_relu;

    for (int row = 0; row < rows; row++) {
        vec1<float> array_slice;
        for (int col = 0; col < cols; col++) {
            float item = array[row][col] <= 0.0 ? 0.0f : 1.0f;
            array_slice.push_back(item);
        }
        deriv_relu.push_back(array_slice);
    }

    return deriv_relu;
}