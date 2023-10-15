#include <iostream>
#include <cmath>

constexpr int N = 1;
constexpr float t = 1;
constexpr float timestep = .00001;
constexpr float G = 9.81;
double result[(int) (t / timestep)][2 * N] = {{0}};

struct Pendolo {
    float l = 0.3;
    float m = 1.0;
    double theta0 = M_PI_4;
    double omega0 = 0.0;
    double state[2 * N] = {M_PI_4, 0.0};
    double state_derived[2 * N] = {0};
};

void f(Pendolo * pend) {
    for (auto i = 0; i < N; ++i) {
        pend->state_derived[i] = pend->state[i + N];
    }
    const double gl = -G * pend->l;
    for (auto i = N; i < 2 * N; ++i) {
        pend->state_derived[i] = sin(pend->state[i - N]) * gl;
    }
}




int main() {
    auto a = Pendolo{};

    for (auto i = 0; i < 2 * N; ++i) {
        result[0][i] =
    }
    for (auto j = 0; j < 10; ++j) {
        f(&a);

        for (auto i = 0; i < 2 * N; ++i) {
            a.state[i] = a.state_derived[i];
            a.state_derived[i] = 0;
        }
    }
    return 0;
}
