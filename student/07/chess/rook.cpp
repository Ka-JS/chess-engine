#include "rook.hh"

/**
 * @brief Constructor for rook
 * @param col The color of the rook
 */

Rook::Rook(ChessColor col):  ChessPiece(col, PieceType::ROOK, "rook")
{

}

/**
 * @brief Get the allowed moves for the rook
 * @param board The current state of the chess board
 * @return coordinates where the rook can move
 */

set<Coord> Rook::get_allowed_moves(ChessBoard const& board) const
{
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

    return moves;
}

/**
 * @brief Check if a move to the destination is valid
 */

void Rook::check_move(const ChessBoard& board, const Coord& dest, set<Coord>& moves) const {
    if (board.coord_in_bounds(dest)) {
        auto piece = board.get_piece_at(dest);
        if (piece == nullptr or piece->get_color() != get_color()) {
            moves.insert(dest);
        }
    }
}
