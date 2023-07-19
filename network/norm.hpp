#include "../types/vec_type.hpp"
#include "../network.hpp"

vec1<float> DL::mean(vec2<float> array) {
    int rows = array.size();
    int cols = array[0].size();
    vec1<float> my_mean;

    for (int row = 0; row < rows; row++) {
        float current_num = 0;
        for (int col = 0; col < cols; col++) {
            current_num += array[row][col];
        }
        my_mean.push_back(current_num / cols);
    }

    return my_mean;
}
vec1<float> DL::std(vec2<float> array) {
    int rows = array.size();
    int cols = array[0].size();

    vec1<float> my_std;
    vec1<float> my_mean = DL::mean(array);

    for (int row = 0; row < rows; row++) {
        float current_num = 0;
        for (int col = 0; col < cols; col++) {
            float power = pow(array[row][col] - my_mean[row], 2.0);
            current_num += power;
        }
        float final_num = sqrt(current_num / cols);
        if (final_num == 0.0f) {
            final_num = 1e-6;
        }
        my_std.push_back(final_num);
    }
    return my_std;
}
vec2<float> DL::norm(vec2<float> array, vec1<float> input_mean, vec1<float> input_std) {
    vec2<float> my_norm;

    int rows = array.size();
    int cols = array[0].size();

    printf("\nrow: %i | col: %i\n", rows, cols);

    for (int row = 0; row < rows; row++) {
        vec1<float> values;
        for (int col = 0; col < cols; col++) {
            printf("mean: %f | std: %f \n", input_mean[row], input_std[row]);
            float value = (array[row][col] - input_mean[row]) / input_std[row];
            printf("value: %f\n", array[row][col] - input_mean[row]);
            values.push_back(value);
        }
        my_norm.push_back(values);
        printf("\n");
    }
    return my_norm;
}