#include "../types/vec_type.hpp"

vec2<float> dot(vec2<float> array1, vec2<float> array2) {
    int rows = array1.size();
    int cols = array1[0].size();
    vec2<float> my_dot;

    for (int row = 0; row < rows; row++) {
        vec1<float> my_dot1;
        for (int col = 0; col < cols; col++) {
            float data = array1[row][col] * array2[row][col];
            my_dot1.push_back(data);
        }
        my_dot.push_back(my_dot1);
    } 

    return my_dot;
}

vec2<float> multi_add(vec2<float> multi1, vec2<float> multi2, vec1<float> add1) {
    vec2<float> my_array;
    int rows = multi1.size();
    int cols = multi1[0].size();

    for (int row = 0; row < rows; row++) {
        vec1<float> array_slice;
        for (int col = 0; col < cols; col++) {
            float result = multi1[row][col] * multi2[row][col] + add1[row];
            array_slice.push_back(result);
        }
        my_array.push_back(array_slice);
    }

    return my_array;
}