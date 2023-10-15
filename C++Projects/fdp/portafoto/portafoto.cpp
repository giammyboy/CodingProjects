//
// Created by Gianmarco Rossi on 06/04/23.
//

#include "portafoto.h"

Port::Port(int dim) {
    if (dim <= 0) {
        this->dim = 3;
    } else {
        this->dim = dim;
    }
    this->columns = new pic[this->dim];
}

bool Port::add(int col, int row) {
    if (col > this->dim || col <= 0 || row <= 0) {
        return false;
    } else {
        auto node = new pic(col, row);
        unsigned int counter = 1;
        auto col_head = &this->columns[col];
        auto prev = col_head;

        while (counter != row && col_head->next != nullptr) {
            prev = col_head;
            ++counter;
            col_head = col_head->next;
        }
        prev->next = node;
        node->next = col_head;
        return true;
    }
}

bool Port::ass(int col, int row, int tar_col, int tar_row) {
    if (col >= 0 && row >= 0 && tar_col >= 0 && tar_row >= 0) {
        if (&this->columns[col] != nullptr) {
            get_pic(tar_col, tar_row).ass = &get_pic(col, row);

        }
    } else {
        return false;
    }
}

Port::pic &Port::get_pic(int col, int row) const {
    unsigned int counter = 1;
    auto col_head = &this->columns[col];
    while (counter != row && col_head->next != nullptr) {
        ++counter;
        col_head = col_head->next;
    }
    return *col_head;
}
