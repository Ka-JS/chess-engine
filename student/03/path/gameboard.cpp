#include "gameboard.hh"
#include <iostream>

using namespace std;


// Constructor
GameBoard::GameBoard()
{

}

// Destructor
GameBoard::~GameBoard(){}

// Fill the gameboard initially: all green buttons are put on the top row
// and all red buttons on the bottom rows, other locations are nullptrs.
void GameBoard::initialFill(){
    for (unsigned int row = 0; row < ROWS; ++row) {
        for (unsigned int col = 0; col < COLUMNS; ++col) {
            board[row][col] = nullptr;
        }
    }
    for (unsigned int col = 0; col < COLUMNS; ++col) {
        board[0][col] = make_unique<char>('G');
    }
    for (unsigned int col = 0; col < COLUMNS; ++col) {
        board[ROWS - 1][col] = make_unique<char>('R');
    }
    board[1][1] = make_unique<char>('o');
    board[2][1] = make_unique<char>('o');
    board[2][2] = make_unique<char>('o');
    board[3][1] = make_unique<char>('o');
}

// Print the gameboard.
void GameBoard::print() const{
    cout << "===============" << endl;
    cout << "|   |";
    for (unsigned int col = 0; col < COLUMNS; ++col){
        cout << " " << col+1;
    }
    cout << " |" << endl << "---------------" << endl;

    for (unsigned int row = 0; row < ROWS; ++row){
        cout << "| " << row+1 << " |";
        for (unsigned int col = 0; col < COLUMNS; ++col) {
            if (board[row][col] != nullptr) {
                cout << " " << *board[row][col];
            } else {
                cout << "  ";
            }
        }
        cout << " |" << endl;
    }
    cout << "===============" << endl;
}

// Return true, if the game is over, i.e. if all red buttons are on the
// top row and all green buttons are on the bottom row.
bool GameBoard::isGameOver() const{

}

// Check the validity of given locations. To be valid, a location must be
// inside the gameboard, it must not be an unused location, and the start
// must have a button, and the destination must not have a button.
// (Implicitly also check that p1 and p2 are not the same points.)
// Returns true, if both the given locations are valid.
bool GameBoard::isValidLocations(const Location& start,
                                 const Location& destination) const{
    if (destination.x >= COLUMNS or destination.y >= ROWS or destination.x < 0 or destination.y < 0) {
        return false;
    }

    if (start.x >= COLUMNS or start.y >= ROWS or start.x < 0 or start.y < 0) {
        return false;
    }

    if (board[start.y][start.x] == nullptr or *board[start.y][start.x] == 'o') {
        return false;
    }

    if (board[destination.y][destination.x] == nullptr or *board[destination.y][destination.x] != 'o'
        or *board[destination.y][destination.x] == 'R' or *board[destination.y][destination.x] == 'G') {
        return false;
    }

    if (start == destination) return false;

    return true;
}

// If possible, move a button from the start location to the destination
// one. A move may consists of horizontal and vertical steps.
// Return true, if move is possible, i.e. if there is a path between
// the given locations.
bool GameBoard::move(const Location& start, const Location& destination){

}
