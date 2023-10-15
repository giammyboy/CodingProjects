//
// Created by Gianmarco Rossi on 27/07/23.
//

#include "axis.h"

Axis::Axis() : value(0) { }

Axis::Axis(uint8_t start_value) {
    if (start_value >= 0 && start_value <= 7) {
        this->value = start_value;
    } else {
        this->value = 0;
    }
}

uint8_t Axis::getValue() const {
    return this->value;
}

void Axis::setValue(uint8_t new_value) {
    if (new_value >= 0 && new_value <= 7) {
        this->value = new_value;
        return;
    } else {
        return;
    }
}

Axis &Axis::operator++() {
    if(this->value >= 7) {
        return *this;
    } else {
        ++this->value;
        return *this;
    }
}

Axis Axis::operator++(int) {
    auto temp = this;
    ++*this;
    return *temp;
}

Axis &Axis::operator--() {
    if(this->value <= 0) {
        return *this;
    } else {
        --this->value;
        return *this;
    }
}

Axis Axis::operator--(int) {
    auto temp = this;
    --*this;
    return *temp;
}

Axis::~Axis() = default;
