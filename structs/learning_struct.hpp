#include "../types/vec_type.hpp"
#include "../network.hpp"

typedef struct {
    vec1<float> x_mean;
    vec1<float> x_std;
    vec1<float> y_mean;
    vec1<float> y_std;
} TrainingNorm;

typedef struct {
    Matrix matrix;
    TrainingNorm norm;
    Dimension dim;
} TrainingData;

typedef struct {
    vec2<float> z1;
    vec2<float> a1;
    vec2<float> z2;
} ZAStorage;

typedef struct {
    vec2<float> delta2;
    vec2<float> delta1;
} DeltaStorage;