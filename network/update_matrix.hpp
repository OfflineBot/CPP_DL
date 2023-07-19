#include "../types/vec_type.hpp"
#include "../network.hpp"
#include "activation.hpp"

ZAStorage DL::forward(Matrix matrix, Normalize norm) {
    int layers = matrix.b.size();

    vec2<float> z1 = multi_add(matrix.w1, norm.input_norm, matrix.b1);
    vec2<float> a1 = sigmoid(z1);

    vec3<float> z;
    vec3<float> a;

    vec2<float> last_z;
    vec2<float> last_a = a1;
    for (int i = 0; i < layers; i++) {
        last_z = multi_add(matrix.w[i], last_a, matrix.b[i]);
        z.push_back(last_z);
        last_a = sigmoid(last_z);
        a.push_back(last_a);
    }
    vec2<float> z2 = multi_add(matrix.w2, last_a, matrix.b2);

    ZAStorage storage = ZAStorage {
        z1,
        a1,
        z,
        a,
        z2,
    };
    return storage;
}

DeltaStorage DL::backward(Matrix matrix, ZAStorage za_storage) {
    int layers = matrix.b.size();
    vec2<float> delta2;
    vec3<float> delta;

    vec2<float> last_delta = delta2;

    for (int i = 0; i < layers; i++) {
        
    }

    vec2<float> delta1;

    DeltaStorage storage = DeltaStorage {
        delta2,
        delta,
        delta1,
    };
    return storage;
}

Matrix DL::update_matrix(Matrix matrix, ZAStorage za_storage, DeltaStorage delta_storage) {

}