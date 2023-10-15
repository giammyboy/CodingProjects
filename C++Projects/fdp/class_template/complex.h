//
// Created by Gianmarco Rossi on 12/04/23.
//

#ifndef CLASS_TEMPLATE_COMPLEX_H
#define CLASS_TEMPLATE_COMPLEX_H

#include <cmath>

class Complex {
protected: // visibile non all'utente ma a una classe derivata sì
    static long double angle(const long double re, const long double im) {
        if (re < 1e-15 && re > -1e-15) {
            return im > 0 ? M_PI_2 : -M_PI_2;
        } else {
            long double temp = atanl(im / re);
            if (re < 0) {
                temp += M_PI;
            }
            return temp;
        }
    }

public:
    virtual long double real() const = 0;

    virtual long double imag() const = 0;

    virtual long double len() const = 0;

    virtual long double ang() const = 0;

    virtual long double norm() const { return sqrt(real() * real() + imag() * imag()); };

    virtual Complex &operator+(const Complex &c) = 0;

    virtual Complex &operator-(const Complex &c) = 0;

    virtual Complex &operator*(const Complex &c) = 0;

    virtual Complex &operator/(const Complex &c) = 0;
};

#endif //CLASS_TEMPLATE_COMPLEX_H
