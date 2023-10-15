//
// Created by Gianmarco Rossi on 23/09/23.
//

#include "board.h"

Board::Board() {
    // Initialize the .game_board with the right position
    for (auto rank = 0; rank <= 7; ++rank) {
        for (auto file = 0; file <= 7; ++file) {
            auto index = rank * 8 + file;
            Piece * pieceToAdd;
            switch (index) {
                case 0: case 7:
                    pieceToAdd = new Piece{Piece::Type::rook, Piece::Color::white};
                    break;
                case 1: case 6:
                    pieceToAdd = new Piece{Piece::Type::knight, Piece::Color::white};
                    break;
                case 2: case 5:
                    pieceToAdd = new Piece{Piece::Type::bishop, Piece::Color::white};
                    break;
                case 3:
                    pieceToAdd = new Piece{Piece::Type::queen, Piece::Color::white};
                    break;
                case 4:
                    pieceToAdd = new Piece{Piece::Type::king, Piece::Color::white};
                    break;
                case 8 ... 15:
                    pieceToAdd = new Piece{Piece::Type::pawn, Piece::Color::white};
                    break;
                case 48 ... 55:
                    pieceToAdd = new Piece{Piece::Type::pawn, Piece::Color::black};
                    break;
                case 56: case 63:
                    pieceToAdd = new Piece{Piece::Type::rook, Piece::Color::black};
                    break;
                case 57: case 62:
                    pieceToAdd = new Piece{Piece::Type::knight, Piece::Color::black};
                    break;
                case 58: case 61:
                    pieceToAdd = new Piece{Piece::Type::bishop, Piece::Color::black};
                    break;
                case 59:
                    pieceToAdd = new Piece{Piece::Type::queen, Piece::Color::black};
                    break;
                case 60:
                    pieceToAdd = new Piece{Piece::Type::king, Piece::Color::black};
                    break;
                default:
                    pieceToAdd = new Piece{};
                    break;
            }
            game_board[index] = new Square(pieceToAdd, new Position{file, rank});
        }
    }

    // Set the eatenPiece to the empty piece to avoid nullptr
    eaten_pieces = new Piece[MAX_EATABLE_PIECES];
}

Board::~Board() {
    delete[] game_board;
}

std::wostream& operator<<(std::wostream &os, const Board &board) {
    // Print the board with the lateral info of position

    // TODO: add lateral space to insert the eaten pieces

    os << "   A  B  C  D  E  F  G  H\n";
    for (auto row = 7; row >= 0; --row) {
        os << row + 1 << "  ";
        for (auto col = 0; col <= 7; ++col) {
            os << board.game_board[row * 8 + col]->squareDisplay() << "  ";
        }
        os << "\n";
    }
    os << board.eaten_pieces->char_to_display;
    os << std::flush;
    return os;
}

void Board::movePiece(Square *start, Square *finish) {
    // Move a Piece from a square to another, if it eats a
    // Piece the eaten Piece is put to .eatenPiece to forward use
    if (start->isEmpty()) {
        return;
    } else {
        if (!finish->isEmpty()) {
            eaten_pieces = finish->grabPiece();
            ++eaten_pieces;
        }
        finish->putPiece(start->grabPiece());
    }
}

int Board::getIndex(const Position *position) { return position->getFile() + position->getRank() * 8; }

bool Board::isSquareEmpty(const Position *square_position) const { return game_board[getIndex(square_position)]->isEmpty(); }

int Board::getIndex(const Square &square) { return square.position->getFile() + square.position->getRank() * 8; }

Piece::Color Board::getSquareColor(const Square &square) const { return game_board[getIndex(square)]->getColor(); }


