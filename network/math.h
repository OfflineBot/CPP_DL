#include "../network.h"

vec2<float> DL::dot(vec2<float> array1, vec2<float> array2) {
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

vec2<float> DL::t(vec2<float> array) {
    vec2<float> t1;
    int rows = array.size();
    int cols = array[0].size();

    for (int col = 0; col < cols; col++) {
        vec1<float> t1_slice;
        for (int row = 0; row < rows; row++) {
            float item = array[row][col];
            t1_slice.push_back(item);
        } 
        t1.push_back(t1_slice);
    } 

    return t1;
}