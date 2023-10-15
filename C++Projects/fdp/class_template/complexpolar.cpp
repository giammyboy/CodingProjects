//
// Created by Gianmarco Rossi on 12/04/23.
//
#include "complex.h"
#include <cmath>

class ComplexPolar : public Complex {
    long double r, theta;

public:

    explicit ComplexPolar(long double r = 0.0, long double theta = 0.0) : r(r), theta(theta) {}

    long double real() const override { return r * cosl(theta); }

    long double imag() const override { return r * sinl(theta); }

    long double len() const override { return r; }

    long double ang() const override { return theta; }

    ComplexPolar &setR(long double r) {
        this->r = r;
        return *this;
    }

    ComplexPolar &setTheta(long double theta) {
        this->theta = theta;
        return *this;
    }

    long double norm() const override {
        return this->r;
    }


    Complex &operator+(const Complex &c) override {
//        long double temp_re, temp_im;
//        temp_re = r * cosl(theta) + (c.len()) * cosl(c.ang());
//        temp_im = r * sinl(theta) + (c.len()) * sinl(c.ang());
//        this->r = sqrt(temp_re * temp_re + temp_im * temp_im);
//        this->theta = angle(temp_re, temp_im);
//        return *this;
        long double temp_re = this->real() + c.real();
        long double temp_im = this->imag() + c.imag();
        return ComplexPolar().setTheta(Complex::angle(temp_re, temp_im)).setR(Complex::norm());
    }

    Complex &operator-(const Complex &c) override {
//        long double temp_re, temp_im;
//        temp_re = r * cosl(theta) - (c.len()) * cosl(c.ang());
//        temp_im = r * sinl(theta) - (c.len()) * sinl(c.ang());
//        this->r = sqrt(temp_re * temp_re + temp_im * temp_im);
//        this->theta = angle(temp_re, temp_im);
//        return *this;
        long double temp_re = this->real() - c.real();
        long double temp_im = this->imag() - c.imag();
        return ComplexPolar().setTheta(Complex::angle(temp_re, temp_im)).setR(Complex::norm());
    }

    Complex &operator*(const Complex &c) override {
//        long double temp_re = r * cosl(theta) * (c.len()) * cosl(c.ang()) - r * sinl(theta) * (c.len()) * sinl(c.ang());
//        long double temp_im = r * cosl(theta) * (c.len()) * sinl(c.ang()) + r * sinl(theta) * (c.len()) * cosl(c.ang());
//        this->r = sqrt(temp_re * temp_re + temp_im * temp_im);
//        this->theta = angle(temp_re, temp_im);
//        return *this;
        long double temp_theta = theta + c.ang();
        long double temp_r = this->len() * c.len();
        return ComplexPolar().setR(temp_r).setTheta(temp_theta);
    }

    Complex &operator/(const Complex &c) override {
        long double temp_theta = theta - c.ang();
        long double temp_r = this->len() / c.len();
        return ComplexPolar().setR(temp_r).setTheta(temp_theta);
    }
};


