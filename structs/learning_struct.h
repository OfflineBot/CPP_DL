#include "../network.h"

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