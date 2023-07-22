#include "network.hpp"
#include "types/vec_type.hpp"
#include "math/t.hpp"
#include "math/dot.hpp"

int testing(vec2<float> test_vec, vec2<float> test_vec1) {
    DL testing;

    Dimension dim = Dimension {
        2,
        4,
        1,
        10,
    };
    Normalize data = testing.normalize(test_vec, test_vec1);
    Matrix matrix = testing.init_matrix(dim);
    TrainingData t_data = testing.training(10000, 0.01, dim, matrix, data);

    // ------- FROM HERE ONLY TESTING ----------
    // printing out normalized input
    vec2<float> my_norm1 = data.input_norm;
    for (int i = 0; i < my_norm1.size(); i++) {
        for (int j = 0; j < my_norm1[0].size(); j++)
            printf("%f\n", my_norm1[i][j]); 
        printf("\n");
    }
    printf("\n");

    vec1<float> test_vec_1 = {
        1.0f, 2.0f, 7.0f
    };
    printf("finished\nprinting tests: \n");
    vec2<float> dot_prod = multi_add(test_vec, test_vec, test_vec_1);
    vec2<float> flip = t(test_vec1);

    printf("flip\n");
    printf("size: (%i %i) | size: (%i %i)\n", test_vec1.size(), test_vec1[0].size(), flip.size(), flip[0].size());
    for (int i = 0; i < flip.size(); i++) {
        for (int j = 0; j < flip[0].size(); j++) {
            printf("%f, ", flip[i][j]);
        }
        printf("\n");
    }

    printf("dot product\n");
    for (int i = 0; i < dot_prod.size(); i++) {
        for (int j = 0; j <dot_prod[0].size(); j++) 
            printf("%f, ", dot_prod[i][j]);
        printf("\n");
    }
    // ----------- END TESTING ---------------

    return 0;
}