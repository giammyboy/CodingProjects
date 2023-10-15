//
// Created by Gianmarco Rossi on 27/07/23.
//

#ifndef CHESS_V4_AXIS_H
#define CHESS_V4_AXIS_H

#include <iostream>

class Axis {
     uint8_t value;
public:
    Axis();
    explicit Axis(uint8_t start_value);

    uint8_t getValue() const;

    void setValue(uint8_t new_value);

    Axis& operator++();
    Axis operator++(int);

    Axis& operator--();
    Axis operator--(int);

    ~Axis();
};


#endif //CHESS_V4_AXIS_H
