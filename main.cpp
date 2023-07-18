#include <iostream>
#include <vector>
#include <iterator>
#include "network.h"


int main() {

    vec2<float> test_vec = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.5f, 7.0f},
        {3.1f, 45.3f, 22.9f},
    };
    vec2<float> test_vec1 = {
        {2.0f},
        {5.5f},
    };

    DL testing;

    Normalize data = testing.normalize(test_vec, test_vec1);

    vec2<float> my_norm1 = data.input_norm;
    for (int i = 0; i < my_norm1.size(); i++) {
        for (int j = 0; j < my_norm1[0].size(); j++)
            printf("%f\n", my_norm1[i][j]); 
        printf("\n");
    }
    printf("\n");
    return 0;
}