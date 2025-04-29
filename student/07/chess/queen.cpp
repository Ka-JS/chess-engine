#include "queen.hh"

/**
 * @brief Constructor for queen
 * @param col The color of the queen
 */

Queen::Queen(ChessColor col) : ChessPiece(col, PieceType::QUEEN, "queen")
{

}

/**
 * @brief Get the allowed moves for the queen
 * @param board The current state of the chess board
 * @return coordinates where the queen can move
 */

set<Coord> Queen::get_allowed_moves(ChessBoard const& board) const {
    set<Coord> moves;
    auto [row, col] = get_position();

    // movement up
    for (int r = row -1; r >=0; --r) {
        Coord dest = {r, col};
        check_move(board, dest, moves);
        if (board.coord_in_bounds(dest) and board.get_piece_at(dest) != nullptr) {
            break;
        }
    }

    // movement down
    for (int r = row +1; r <8; ++r) {
        Coord dest = {r, col};
        check_move(board, dest, moves);
        if (board.coord_in_bounds(dest) and board.get_piece_at(dest) != nullptr) {
            break;
        }
    }

    // movement left
    for (int c = col -1; c >=0; --c) {
        Coord dest = {row, c};
        check_move(board, dest, moves);
        if (board.coord_in_bounds(dest) and board.get_piece_at(dest) != nullptr) {
            break;
        }
    }

    // movement right
    for (int c = col +1; c <8; ++c) {
        Coord dest = {row, c};
        check_move(board, dest, moves);
        if (board.coord_in_bounds(dest) and board.get_piece_at(dest) != nullptr) {
            break;
        }
    }
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

void Queen::check_move(const ChessBoard& board, const Coord& dest, set<Coord>& moves) const {
    if (board.coord_in_bounds(dest)) {
        auto piece = board.get_piece_at(dest);
        if (piece == nullptr or piece->get_color() != get_color()) {
            moves.insert(dest);
        }
    }
}
