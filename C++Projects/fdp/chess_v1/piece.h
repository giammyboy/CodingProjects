//
// Created by Gianmarco Rossi on 14/05/23.
//

#ifndef CHESS_V1_PIECE_H
#define CHESS_V1_PIECE_H


class Piece {
protected:

static int abs(int num) {
    return num > 0 ? num : -num;
}

static bool inBoard(const int &other) {
    return other >= 0 && other <= 63;
}

[[nodiscard]] static int col(const int &n) {
    return n % 8;
}

[[nodiscard]] static int row(const int &n) {
    return n / 8;
}

[[nodiscard]] int col() const {
    return pos % 8;
}

[[nodiscard]] int row() const {
    return pos / 8;
}

[[nodiscard]] bool notSame(const int &other) const {
    return pos != other;
}


[[nodiscard]] bool inSameRow(const int &other) const {
    return pos / 8 == other / 8;
}

[[nodiscard]] bool inSameCol(const int &other) const {
    return pos % 8 == other % 8;
}

[[nodiscard]] bool inCorner(const int &other) const {
    if (abs(col() - col(other)) == 1 && abs(row() - row(other)) == 1) {
        return true;
    } else {
        return false;
    }
}

[[nodiscard]] bool inEdge(const int &other) const {
    if ((abs(col() - col(other)) == 1 && abs(row() - row(other)) == 0) ||
        (abs(col() - col(other)) == 0 && abs(row() - row(other)) == 1)) {
        return true;
    } else {
        return false;
    }
}

[[nodiscard]] bool isNear(const int &other) const {
    if (inCorner(other) && inEdge(other)) {
        return true;
    } else {
        return false;
    }
}

[[nodiscard]] bool inDiagonal(const int &other) const {
    if (abs(row() - row(other)) == abs(col() - col(other))) {
        return true;
    } else {
        return false;
    }
}

public:

    void setPos(int s_pos);
    [[nodiscard]] virtual bool isLegit(const int &other) const = 0;

    char color;
    int pos;
    char name;
};


#endif //CHESS_V1_PIECE_H
