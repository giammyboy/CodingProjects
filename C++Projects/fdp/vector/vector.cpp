//
// Created by Gianmarco Rossi on 03/04/23.
//

#include "vector.h"

vector::vector() : dimension(2) {
  components = new double[2];
  for (int i = 0; i < this->dimension; ++i) {
    this->components[i] = 0;
  }
}

vector::vector(unsigned int n) : dimension(n) {
  components = new double[this->dimension];
  for (int i = 0; i < this->dimension; ++i) {
    this->components[i] = 0;
  }
}