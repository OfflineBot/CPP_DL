
#include <iostream>
#include <vector>
#include <iterator>
#include "network.hpp"
#include "./network/matrix.hpp"
#include "./network/norm.hpp"
#include "./math/t.hpp"
#include "./math/dot.hpp"

#include "testing.hpp"

int main() {

    vec2<float> test_vec = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.5f, 7.0f},
        {3.1f, 45.3f, 22.9f},
    };
    vec2<float> test_vec1 = {
        {1.0f},
        {2.0f},
        {7.0f},
    };

    DL network;
    int iterations = 10000;
    float learning_rate = 0.01;
    Dimension dim = Dimension {
        2,
        10,
        1,
        5,
    };
    Normalize norm = network.normalize(test_vec, test_vec1);
    Matrix matrix = network.init_matrix(dim);
    TrainingData data = network.training(iterations, learning_rate, dim, matrix, norm); 


    // TESTING AREA
    testing(test_vec, test_vec1);
    
    return 0;
}