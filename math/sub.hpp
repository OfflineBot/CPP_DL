#include "../types/vec_type.hpp"

vec2<float> sub(vec2<float> array1, vec2<float> array2) {
    int rows = array1.size();
    int cols = array1[0].size();
    vec2<float> subtract;
    for (int row = 0; row < rows; row++) {
        vec1<float> array_slice;
        for (int col = 0; col < cols; col++) {
            float item = array1[row][col] - array2[row][col];
            array_slice.push_back(item);
        }
        subtract.push_back(array_slice);
    }

    return subtract;
}