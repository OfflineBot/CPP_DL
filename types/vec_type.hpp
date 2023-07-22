#ifndef VEC_TYPE_H
#define VEC_TYPE_H

#include <vector>
#include "vec1_operator.hpp"
#include "vec2_operator.hpp"

template<typename T>
using vec1 = std::vector<T>;
template<typename T>
using vec2 = std::vector<vec1<T>>;
template<typename T>
using vec3 = std::vector<vec2<T>>;

#endif