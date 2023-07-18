#include <vector>
#include <random>
#include <cmath>

using namespace std;

template<typename T>
using vec1 = vector<T>;
template<typename T>
using vec2 = vector<vec1<T>>;
template<typename T>
using vec3 = vector<vec2<T>>;

typedef struct
{
    vec2<float> input;
    vec1<float> input_mean;
    vec1<float> input_std;
    vec2<float> input_norm;

    vec2<float> output;
    vec1<float> output_mean;
    vec1<float> output_std;
    vec2<float> output_norm;
} Normalize;

typedef struct {
    vec2<float> w1;
    vec1<float> b1;
    vec3<float> w;
    vec2<float> b;
    vec2<float> w2;
    vec1<float> b2;
} Matrix;

class DL {
    // ---------- SHOULD BE PRIVATE ------------
public:

    vec1<float> mean(vec2<float> array) {
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

    vec1<float> std(vec2<float> array) {
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
    vec2<float> norm(vec2<float> array, vec1<float> array_mean, vec1<float> array_std) {
        vec2<float> my_norm;

        int rows = array.size();
        int cols = array[0].size();

        printf("\nrow: %i | col: %i\n", rows, cols);

        for (int row = 0; row < rows; row++) {
            vec1<float> values;
            for (int col = 0; col < cols; col++) {
                printf("mean: %f | std: %f \n", array_mean[row], array_std[row]);
                float value = (array[row][col] - array_mean[row]) / array_std[row];
                printf("value: %f\n", array[row][col] - array_mean[row]);
                values.push_back(value);
            }
            my_norm.push_back(values);
            printf("\n");
        }
        
        return my_norm;
    }


public:
    Normalize normalize(vec2<float> input_array, vec2<float> output_array) { 

        vec1<float> input_mean = DL::mean(input_array);
        vec1<float> input_std = DL::std(input_array);
        vec2<float> input_norm = DL::norm(input_array, input_mean, input_std);

        vec1<float> output_mean = DL::mean(output_array);
        vec1<float> output_std = DL::std(output_array);
        vec2<float> output_norm = DL::norm(output_array, output_mean, output_std);

        Normalize data = Normalize {
            input_array,
            input_mean,
            input_std,
            input_norm,
            output_array,
            output_mean,
            output_std,
            output_norm,
        };
        return data;
    }

};