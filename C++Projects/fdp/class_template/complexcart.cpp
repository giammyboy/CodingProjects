//
// Created by JESUS on 25/12/0000.
//
#include "complex.h"
#include <cmath>

class ComplexCart : public Complex {
    long double re, im;

public:
    explicit ComplexCart(long double re = 0.0, long double im = 0.0) : re(re), im(im) {}

    long double real() const override { return re; }

    long double imag() const override { return im; }

    long double len() const override { return this->norm(); }

    long double ang() const override { return Complex::angle(re, im); }

    ComplexCart &con() const {
        return ComplexCart().setRe(re).setIm(-im);
    }

    ComplexCart &setRe(long double re) {
        this->re = re;
        return *this;
    }

    ComplexCart &setIm(long double im) {
        this->im = im;
        return *this;
    }

    Complex &operator+(const Complex &c) override {
        this->re += c.real();
        this->im += c.imag();
        return *this;
    }

    Complex &operator-(const Complex &c) override {
        this->re -= c.real();
        this->im -= c.imag();
        return *this;
    }

    Complex &operator*(const Complex &c) override {
        long double temp_re = re * c.real() - im * c.imag();
        long double temp_im = re * c.imag() + im * c.real();
        this->re = temp_re;
        this->im = temp_im;
        return *this;
    }


};
