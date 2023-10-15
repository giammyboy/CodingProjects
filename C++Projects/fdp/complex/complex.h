//
// Created by Gianmarco Rossi on 23/04/23.
//

#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#import "complexcart.h"

class complex : public complexcart {
    const long double im() const override {
        return a;
    }
    const long double re() const override {
        return b;
    }


};


#endif //COMPLEX_COMPLEX_H
