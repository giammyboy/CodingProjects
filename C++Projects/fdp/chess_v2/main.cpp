#include <iostream>
#include "Piece.h"
#include <unicode/utf8.h>
#include <unicode/utypes.h>
#include "Board.h"

void bit(uint64_t number) {
    uint64_t slider = 0x8000000000000000; // 2^63 = 9223372036854775808
    for (int i = 0; i < 64; i++) {
        std::cout << ((number & (slider >> i)) >> (63 - i)) << " ";
    }
    std::cout << std::endl;
}

void sbit(uint64_t number) {
    uint64_t slider = 0x8000000000000000; // 2^63 = 9223372036854775808
    char square[64];
    for (int i = 0; i < 64; i++) {
        if ((number & (slider >> i))) {
            square[63 - i] = '1';
        } else {
            square[63 - i] = '0';
        }
    }

    for (int rank = 7; rank >= 0; rank--) {
        for (int file = 0; file < 8; file++) {
            std::cout << square[(rank * 8) + file] << "  ";
        }
        std::cout << std::endl;
    }
}


int main() {

    auto a = new Board();
//    std::cout << *a << std::endl;
//    a->board[8].setRank(3);
//    std::cout << *a << std::endl;
//    sbit(0x8040201008040201);
//    std::cout << std::endl;
//    sbit(0x0102040810204080);
//    std::cout << std::endl;
//    sbit(0x0000000000070507);
//    std::cout << std::endl;
//    sbit(0x0000000000070507);
//    std::cout << std::endl;
//    sbit(0x0000000A1100110A);
    uint8_t file = 1, move = 10;
    uint8_t rank_1_bitmask = 0b11100000;
    uint8_t rank_2_bitmask = 0b10100000;
    uint8_t rank_3_bitmask = 0b11100000;
    uint8_t rank_4_bitmask = 0b0;
    uint8_t rank_5_bitmask = 0b0;
    uint8_t rank_6_bitmask = 0b0;
    uint64_t move_bitmask = 0;
    uint64_t possible_move_bitmaks = 0;

    if (file <= 1) {
        rank_4_bitmask |= rank_1_bitmask << (1 - file);
        rank_5_bitmask |= rank_2_bitmask << (1 - file);
        rank_6_bitmask |= rank_3_bitmask << (1 - file);
    } else {
        rank_1_bitmask >> (file - 1);
        rank_2_bitmask >> (file - 1);
        rank_3_bitmask >> (file - 1);
    }

    possible_move_bitmaks = (possible_move_bitmaks | rank_4_bitmask) << move;
    possible_move_bitmaks = (possible_move_bitmaks | rank_5_bitmask) << (move + 8);
    possible_move_bitmaks = (possible_move_bitmaks | rank_6_bitmask) << (move + 16);

    sbit(possible_move_bitmaks);
    return 0;
}