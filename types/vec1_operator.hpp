#include "vec_type.hpp"

vec1<float> operator+(vec1<float> array1, vec1<float> array2) {
    int rows = array1.size();
    vec1<float> result;

    for (int row = 0; row < rows; row++) {
        float item = array1[row] + array2[row];
        result.push_back(item);
    }

    return result;
}

vec1<float> operator-(vec1<float> array1, vec1<float> array2) {
    int rows = array1.size();
    vec1<float> result;

    for (int row = 0; row < rows; row++) {
        float item = array1[row] - array2[row];
        result.push_back(item);
    }

    return result;
}

vec1<float> operator*(vec1<float> array1, float multi_item) {
    int rows = array1.size();
    vec1<float> result;

    for (int row = 0; row < rows; row++) {
        float item = array1[row] * multi_item;
        result.push_back(item);
    }

    return result;
}

vec1<float> operator/(vec1<float> array1, vec1<float> array2) {
    int rows = array1.size();
    vec1<float> result;

    for (int row = 0; row < rows; row++) {
        float item = array1[row] / array2[row];
        result.push_back(item);
    }

    return result;
}

vec1<float> operator*(vec1<float> array1, float multi_item) {
    int rows = array1.size();
    vec1<float> result;

    for (int row = 0; row < rows; row++) {
        float item = array1[row] * multi_item;
        result.push_back(item);
    }

    return result;
}