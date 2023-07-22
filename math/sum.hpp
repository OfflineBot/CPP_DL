#include "../types/vec_type.hpp"

vec1<float> sum_axis(vec2<float> array) {
    int rows = array.size();
    int cols = array[0].size();
    vec1<float> final_array;
    
    for (int col = 0; col < cols; col++) {
        float item = 0;
        for (int row = 0; row < rows; row++) {
            item += array[row][col]; 
        }
        final_array.push_back(item);
    }
    return final_array; 
}