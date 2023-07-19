#include "../types/vec_type.hpp"

vec2<float> t(vec2<float> array) {
    vec2<float> my_array;
    int rows = array.size();
    int cols = array[0].size();

    for (int col = 0; col < cols; col++) {
        vec1<float> slice;
        for (int row = 0; row < rows; row++) {
            float item = array[row][col];
            slice.push_back(item);
        }
        my_array.push_back(slice);
    }
        
    return my_array;
}