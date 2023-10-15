//
// Created by Gianmarco Rossi on 13/10/23.
//

#ifndef PLOT_PENDOLUM_H
#define PLOT_PENDOLUM_H

#include <matplot/matplot.h>

class System {

    class vec {
        int n;
        double* v;
    public:
        vec(const double* array, int dim);
        vec(int dim);

        vec& operator+(const vec& other);
        vec& operator*(const vec& other);
        vec& operator*(const double s);

    };

    class RungeKutta {
        double h;
        int n;
        vec& (* f) (vec& t);

    public:
        RungeKutta(vec& (* f) (vec& t), double& h);

        vec& integrate_t(vec& yn);

        vec* integrate(vec& y0);
    };



};


#endif //PLOT_PENDOLUM_H
