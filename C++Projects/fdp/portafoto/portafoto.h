//
// Created by Gianmarco Rossi on 06/04/23.
//

#ifndef PORTAFOTO_PORTAFOTO_H
#define PORTAFOTO_PORTAFOTO_H


class Port {
public:
    class pic {
    public:
        unsigned int col;
        unsigned int row;
        pic *next;
        pic *ass;

        pic(unsigned int col, unsigned int row) : col(col), row(row), next(nullptr) { }
        pic() : col(1), row(1), next(nullptr) { }
    };

    Port(int dim);

    bool add(int col, int row);
    bool ass(int col, int row, int tar_col, int tar_row);

    pic &get_pic(int col, int row) const;
    unsigned int dim;
    pic *columns;
};


#endif //PORTAFOTO_PORTAFOTO_H
