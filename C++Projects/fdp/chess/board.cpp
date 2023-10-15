//
// Created by Gianmarco Rossi on 04/05/23.
//

#include "board.h"


Board::Board() {
    board = new Square[64];
    for (int i = 0; i <= 63; i++) {
        if (i == 8) {
            for (; i <= 15; i++) {
                auto temp = board + i;
                temp->setPiece(new Pawn(W, i));
            }
            for (i = 48; i <= 55; i++) {
                auto temp = board + i;
                temp->setPiece(new Pawn(B, i));
            }
            i = 55;
        } else {
            auto temp = board + i;
            temp->id = i;
            switch (i) {
                case 0:
                    temp->setPiece(new Rook(W, i));
                    break;
                case 1:
                    temp->setPiece(new Knight(W, i));
                    break;
                case 2:
                    temp->setPiece(new Bishop(W, i));
                    break;
                case 3:
                    temp->setPiece(new Queen(W, i));
                    break;
                case 4:
                    temp->setPiece(new King(W, i));
                    break;
                case 5:
                    temp->setPiece(new Bishop(W, i));
                    break;
                case 6:
                    temp->setPiece(new Knight(W, i));
                    break;
                case 7:
                    temp->setPiece(new Rook(W, i));
                    break;
                case 56:
                    temp->setPiece(new Rook(B, i));
                    break;
                case 57:
                    temp->setPiece(new Knight(B, i));
                    break;
                case 58:
                    temp->setPiece(new Bishop(B, i));
                    break;
                case 59:
                    temp->setPiece(new Queen(B, i));
                    break;
                case 60:
                    temp->setPiece(new King(B, i));
                    break;
                case 61:
                    temp->setPiece(new Bishop(B, i));
                    break;
                case 62:
                    temp->setPiece(new Knight(B, i));
                    break;
                case 63:
                    temp->setPiece(new Rook(B, i));
                    break;
                default:
                    temp->setPiece(nullptr);
            }
        }
    }

}

std::ostream &operator<<(std::ostream &os, const Board &b) {
    for (int row = 7; row >= 0; row--) {
        for (int col = 0; col <= 7; col++) {
            auto temp = b.board + row * 8 + col;
            if (temp->current != nullptr) {
                os << temp->current->name << "  ";
            } else {
                os << "  ";
            }
        }
        os << std::endl;
    }
    return os;
}
