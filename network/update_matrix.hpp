#include "../types/vec_type.hpp"
#include "../network.hpp"
#include "activation.hpp"
#include "../math/dot.hpp"
#include "../math/t.hpp"
#include "../math/multiply.hpp"
#include "../math/sub.hpp"
#include "../math/sum.hpp"

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

DeltaStorage DL::backward(Matrix &matrix, ZAStorage &za_storage, Normalize &norm) {
    int layers = matrix.b.size();
    vec2<float> delta2 = multiply(dot(norm.output_norm, t(za_storage.z2)), deriv_sigmoid(za_storage.z2));
    vec3<float> delta;

    vec2<float> last_delta = delta2;

    for (int i = 0; i < layers; i++) {
        if (i == 0) {
            last_delta = multiply(dot(last_delta, t(matrix.w2)), deriv_sigmoid(za_storage.z[layers - i]));
            delta.push_back(last_delta);
        } else {
            last_delta = multiply(dot(last_delta, t(matrix.w[layers + 1 - i])), deriv_sigmoid(za_storage.z[layers - i]));
            delta.push_back(last_delta);
        }
    }

    vec2<float> delta1 = multiply(dot(last_delta, t(matrix.w[0])), deriv_sigmoid(za_storage.z1));

    DeltaStorage storage = DeltaStorage {
        delta2,
        delta,
        delta1,
    };
    return storage;
}

Matrix DL::update_matrix(Matrix matrix, ZAStorage za_storage, DeltaStorage delta_storage, Normalize norm, float learning_rate) {
    int layers = matrix.b.size() - 1;
    int a_index = za_storage.a.size() - 1;

    matrix.w1 = matrix.w1 - dot(delta_storage.delta1, t(norm.input_norm)) * learning_rate;
    matrix.b1 = matrix.b1 - sum_axis(delta_storage.delta1) * learning_rate;

    for (int i = 0; i < layers; i++) {
        matrix.w[i] = matrix.w[i] - dot(delta_storage.delta[i], t(za_storage.a[i])) * learning_rate;
        matrix.b[i] = matrix.b[i] - sum_axis(delta_storage.delta[i]) * learning_rate;
    }

    matrix.w2 = matrix.w2 - dot(za_storage.a[a_index], delta_storage.delta2) * learning_rate;
    matrix.b2 = matrix.b2 - sum_axis(delta_storage.delta2) * learning_rate;

    return matrix;
}