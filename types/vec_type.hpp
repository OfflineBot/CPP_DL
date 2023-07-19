#include <vector>

template<typename T>
using vec1 = std::vector<T>;
template<typename T>
using vec2 = std::vector<vec1<T>>;
template<typename T>
using vec3 = std::vector<vec2<T>>;