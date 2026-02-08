#include "bishop.hh"

/**
 * @brief Constructor for bishop
 * @param col The color of the bishop
 */

Bishop::Bishop(ChessColor col) : ChessPiece(col, PieceType::BISHOP, "bishop")
{

}


/**
 * @brief Get the allowed moves for the bishop
 * @param board The current state of the chess board
 * @return coordinates where the bishop can move
 */

set<Coord> Bishop::get_allowed_moves(const ChessBoard &board) const
{
    set<Coord> moves;
    auto [row, col] = get_position();

    // movement upright
    for (int r = row -1, c = col +1; r >=0 and c <8; --r, ++c) {
        Coord dest = {r, c};
        check_move(board, dest, moves);
        if (board.coord_in_bounds(dest) and board.get_piece_at(dest) != nullptr) {
            break;
        }
    }

    // movement downright
    for (int r = row +1, c = col +1; r <8 and c <8; ++r, ++c) {
        Coord dest = {r, c};
        check_move(board, dest, moves);
        if (board.coord_in_bounds(dest) and board.get_piece_at(dest) != nullptr) {
            break;
        }
    }

    // movement downleft
    for (int r = row +1, c = col -1; r <8 and c >=0; ++r, --c) {
        Coord dest = {r, c};
        check_move(board, dest, moves);
        if (board.coord_in_bounds(dest) and board.get_piece_at(dest) != nullptr) {
            break;
        }
    }

    // movement upleft
    for (int r = row -1, c = col -1; r >=0 and c >=0; --r, --c) {
        Coord dest = {r, c};
        check_move(board, dest, moves);
        if (board.coord_in_bounds(dest) and board.get_piece_at(dest) != nullptr) {
            break;
        }
    }

    return moves;
}

/**
 * @brief Check if a move to the destination is valid
 */

void Bishop::check_move(const ChessBoard& board, const Coord& dest, set<Coord>& moves) const {
    if (board.coord_in_bounds(dest)) {
        auto piece = board.get_piece_at(dest);
        if (piece == nullptr or piece->get_color() != get_color()) {
            moves.insert(dest);
        }
    }
}
