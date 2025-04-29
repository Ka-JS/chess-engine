#include "rook.hh"
#include <set>

Rook::Rook(ChessColor col):  ChessPiece(col, PieceType::ROOK, "rook")
{

}

set<Coord> Rook::get_allowed_moves(const ChessBoard &board) const
{
    set<Coord> moves;
    Coord current = get_position();

    // movement up
    for (int row = current.row -1; row >=0; --row){
        Coord target ={row, current.col};
        auto piece = board.get_piece_at(target);
        if (piece == nullptr){
            moves.insert(target);
        }else{
            if (piece->get_color() != get_color()) {
                moves.insert(target);
            }
            break;
        }
    }

    //movement down
    for (int row = current.row +1; row <0; ++row){
        Coord target ={row, current.col};
        auto piece = board.get_piece_at(target);
        if (piece == nullptr){
            moves.insert(target);
        }else{
            if (piece->get_color() != get_color()) {
                moves.insert(target);
            }
            break;
        }
    }

    //movement left
    for (int col = current.col -1; col >=0; --col) {
        Coord target = {current.row, col};
        auto piece = board.get_piece_at(target);
        if (piece == nullptr) {
            moves.insert(target);
        }else{
            if (piece->get_color() != get_color()) {
                moves.insert(target);
            }
            break;
        }
    }
    //movement right
    for (int col = current.col +1; col <8; ++col) {
        Coord target = {current.row, col};
        auto piece = board.get_piece_at(target);
        if (piece == nullptr) {
            moves.insert(target);
        }else{
            if (piece->get_color() != get_color()) {
                moves.insert(target);
            }
            break;
        }
    }

    return moves;



}
