//
// Created by Gianmarco Rossi on 13/10/23.
//

#include "pendolum.h"
#include "include/NumCpp.hpp"


System::RungeKutta::RungeKutta(vec& (* f) (vec& t), double& h) : f{nullptr}, h{0.01} {}

System::vec& System::RungeKutta::integrate_t(vec& yn) {
//    cdef cnp.ndarray k1 = h*fun(yn)
//    cdef cnp.ndarray k2 = h*fun(yn + (1/2)*k1)
//    cdef cnp.ndarray k3 = h*fun(yn + (1/2)*k2)
//    cdef cnp.ndarray k4 = h*fun(yn + k3)
//    return yn + (1/6)*k1 + (1/3)*k2 + (1/3)*k3 + (1/6)*k4

    auto k1 = f(yn) * h;
    auto k2 = f(yn + k1 * .5) * h;
    auto k3 = f(yn + k2 * .5) * h;
    auto k4 = f(yn + k3) * h;

    return yn + k1 * (1.0/6) + k2 * (1.0/3) + k3 * (1.0/3) + k4 * (1.0/6);

}

System::vec *System::RungeKutta::integrate(System::vec &y0) {
    return nullptr;
}

System::vec::vec(const double *array, int dim) : n(dim){
    v = new double[n];
    for (int i = 0; i < n; ++i) {
        v[i] = array[i];
    }
}

System::vec::vec(int dim) : n(dim) {
    v = new double[n];
    for (int i = 0; i < n; ++i) {
        v[i] = 0;
    }
}

System::vec &System::vec::operator+(const vec& other) {
    auto res = new vec(n);
    for (int i = 0; i < n; ++i) {
        res->v[i] = v[i] + other.v[i];
    }
    return *res;
}

System::vec &System::vec::operator*(const System::vec &other) {
    auto res = new vec(n);
    for (int i = 0; i < n; ++i) {
        res->v[i] = v[i] * other.v[i];
    }
    return *res;
}

System::vec &System::vec::operator*(const double s) {
    for (int i = 0; i < n; ++i) {
        v[i] *= s;
    }
    return *this;
}
