//
// Created by Gianmarco Rossi on 20/07/23.
//

#include "rules.h"

bool Rules::kingMove(Piece * piece, int move) {
    uint8_t rank_1_bitmask = 0b11100000;
    uint8_t rank_2_bitmask = 0b10100000;
    uint8_t rank_3_bitmask = 0b11100000;
    uint64_t move_bitmask = 0b1 << move;
    uint64_t possible_move_bitmaks = 0;

    if (piece->getFile() <= 1) {
        rank_1_bitmask << (1 - piece->getFile());
        rank_2_bitmask << (1 - piece->getFile());
        rank_3_bitmask << (1 - piece->getFile());
    } else {
        rank_1_bitmask >> (piece->getFile() - 1);
        rank_2_bitmask >> (piece->getFile() - 1);
        rank_3_bitmask >> (piece->getFile() - 1);
    }

    possible_move_bitmaks = (possible_move_bitmaks | rank_1_bitmask) << move;
    possible_move_bitmaks = (possible_move_bitmaks | rank_2_bitmask) << (move + 8);
    possible_move_bitmaks = (possible_move_bitmaks | rank_3_bitmask) << (move + 16);

    if ((move_bitmask & possible_move_bitmaks) == 0) {
        return false;
    } else {
        return true;
    }


}
