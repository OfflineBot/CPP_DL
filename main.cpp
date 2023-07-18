#include <iostream>
#include <vector>
#include <iterator>
#include "network.h"


int main() {

    vec2<float> test_vec = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.5f, 7.0f},
    };
    vec2<float> test_vec1 = {
        {2.0f},
        {5.5f},
    };

    DL testing;

    Normalize data = testing.normalize(test_vec, test_vec1);

    for (int i = 0; i < data.input_std.size(); i++)
        printf(" %f ", data.input_std[i]);    
    printf("\n");

    for (int i = 0; i < data.input_norm.size(); i++) {
        for (int j = 0; j < data.input_norm[0].size(); j++) 
            printf(" %f ", data.input_norm[i][j]);
        printf("\n");
    }

    return 0;
}