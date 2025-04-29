#include "king.hh"

/**
 * @brief Constructor for king
 * @param col The color of the king
 */

King::King(ChessColor col) : ChessPiece(col, PieceType::KING, "king")
{

}

/**
 * @brief Get the allowed moves for the king
 * @param board The current state of the chess board
 * @return coordinates where the king can move
 */

set<Coord> King::get_allowed_moves(ChessBoard const& board) const {
    set<Coord> moves;
    auto [row, col] = get_position();

    // check all 8 moves
    check_move(board, {row - 1, col}, moves);     // movement up
    check_move(board, {row + 1, col}, moves);     // movement down
    check_move(board, {row, col - 1}, moves);     // movement left
    check_move(board, {row, col + 1}, moves);     // movement right
    check_move(board, {row - 1, col - 1}, moves); // movement upright
    check_move(board, {row - 1, col + 1}, moves); // movement downright
    check_move(board, {row + 1, col - 1}, moves); // movement downleft
    check_move(board, {row + 1, col + 1}, moves); // movement upright

    return moves;
}

void King::check_move(const ChessBoard& board, const Coord& dest, set<Coord>& moves) const {
    if (board.coord_in_bounds(dest)) {
        auto piece = board.get_piece_at(dest);
        if (piece == nullptr or piece->get_color() != get_color()) {
            moves.insert(dest);
        }
    }
}
