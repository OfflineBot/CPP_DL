#include <random>
#include "../types/vec_type.hpp"
#include "../network.hpp"

using namespace std;
vec1<float> DL::random_array(int cols) {
    vec1<float> my_vec;
    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_real_distribution<float> distr(0.0, 1.0);

    for (int col = 0; col < cols; col++)
        my_vec.push_back(distr(generator));

    return my_vec;
}

vec2<float> DL::random_array(int rows, int cols) {
    vec2<float> my_vec2;
    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_real_distribution<float> distr(0.0, 1.0);

    for (int row = 0; row < rows; row++) {
        vec1<float> my_vec1;
        for (int col = 0; col < cols; col++)
            my_vec1.push_back(distr(generator));
        my_vec2.push_back(my_vec1);
    }

    return my_vec2;
}

vec3<float> DL::random_array(int items, int rows, int cols) {
    vec3<float> my_vec3;
    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_real_distribution<float> distr(0.0, 1.0);

    for(int item = 0; item < items; item++) {
        vec2<float> my_vec2;
        for (int row = 0; row < rows; row++) {
            vec1<float> my_vec1;
            for (int col = 0; col < cols; col++)
                my_vec1.push_back(distr(generator));
            my_vec2.push_back(my_vec1);
        }
        my_vec3.push_back(my_vec2);
    }

    return my_vec3;
}