#include "gameboard.hh"
#include <iostream>
#include <cstdlib>

using namespace std;


// Constructor
GameBoard::GameBoard()
{
    initialFill();
}

// Destructor
GameBoard::~GameBoard(){}

// Fill the gameboard initially: all green buttons are put on the top row
// and all red buttons on the bottom rows, other locations are nullptrs.
void GameBoard::initialFill(){
    for (unsigned int row = 0; row < ROWS; ++row) {
        for (unsigned int col = 0; col < COLUMNS; ++col) {
            board[row][col] = nullptr; // Set all locations as empty
        }
    }
    for (unsigned int col = 0; col < COLUMNS; ++col) {
        board[0][col] = make_unique<char>('G'); //Green at the top
    }
    for (unsigned int col = 0; col < COLUMNS; ++col) {
        board[ROWS - 1][col] = make_unique<char>('R'); //Red on the bottom
    }
    board[1][1] = make_unique<char>('o'); //placing the 'o' buttons
    board[2][1] = make_unique<char>('o');
    board[2][2] = make_unique<char>('o');
    board[3][1] = make_unique<char>('o');
}

// Print the gameboard.
void GameBoard::print() const{
    cout << "===============" << endl;
    cout << "|   |";
    for (unsigned int col = 0; col < COLUMNS; ++col){
        cout << " " << col+1; //column numbers
    }
    cout << " |" << endl << "---------------" << endl;

    for (unsigned int row = 0; row < ROWS; ++row){
        cout << "| " << row+1 << " |"; //row numbers
        for (unsigned int col = 0; col < COLUMNS; ++col) {
            if (board[row][col] != nullptr) {
                cout << " " << *board[row][col]; //buttons (G,R,o)
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
    for (unsigned int col = 0; col < COLUMNS; col++){
        if (*board[0][col] == 'o' or *board[0][col] == 'G'){
            return false; // returns false if top row has o or G
        }
    }
    for (unsigned int col = 0; col < COLUMNS; col++){
        if (*board[ROWS-1][col] == 'o' or *board[ROWS-1][col] == 'R'){
            return false; // returns false if bottom row has o or R
        }
    }

    return true; //Game over if no 'o' or 'G' on top and no 'o' or 'R' on bottom
}

// Check the validity of given locations. To be valid, a location must be
// inside the gameboard, it must not be an unused location, and the start
// must have a button, and the destination must not have a button.
// (Implicitly also check that p1 and p2 are not the same points.)
// Returns true, if both the given locations are valid.
bool GameBoard::isValidLocations(const Location& start,
                                 const Location& destination) const{
    if (destination.x >= COLUMNS or destination.y >= ROWS) {
        return false; // destination not within boundaries
    }

    if (start.x >= COLUMNS or start.y >= ROWS) {
        return false; // start not within boundaries
    }

    if (board[start.y][start.x] == nullptr or
       *board[start.y][start.x] == 'o') {
        return false; //Start location must contain a valid button
    }

    if (board[destination.y][destination.x] == nullptr or
       *board[destination.y][destination.x] != 'o' or
       *board[destination.y][destination.x] == 'R' or
       *board[destination.y][destination.x] == 'G') {
        return false; // Destination must be empty
    }

    if (start == destination) return false;// Start and destination cannot be the same

    return true;
}

// If possible, move a button from the start location to the destination
// one. A move may consists of horizontal and vertical steps.
// Return true, if move is possible, i.e. if there is a path between
// the given locations.
bool GameBoard::move(const Location& start, const Location& destination){
    if(!isValidLocations(start, destination)){
        return false; // return false if the move wasnt valid
    }

    // pure horizontal path
    if (start.y == destination.y){
        unsigned int minX, maxX;
        if (start.x < destination.x){
            minX = start.x;
            maxX = destination.x;
        }else{
            minX = destination.x;
            maxX = start.x;
        }
        for (unsigned int x = minX +1; x < maxX; x++){
            if (board[start.y][x] == nullptr or *board[start.y][x] != 'o'){
                return false; //if path blocked
            }
        }
    }

    //moves on different rows, we do a three part path

    else{
        bool found = false;
        // finding the middle column
        for (unsigned int c = 0; c < COLUMNS; c++){
            bool seg1 = true, seg2 = true, seg3 = true;

            // segment 1 (seg1) moving horizontally to the middle column
            {
                unsigned int minX, maxX;
                if (start.x < c) {
                    minX = start.x;
                    maxX = c;
                } else {
                    minX = c;
                    maxX = start.x;
                }
                for (unsigned int x = minX + 1; x < maxX; x++) {
                    if (board[start.y][x] == nullptr or *board[start.y][x] != 'o') {
                        seg1 = false; //seg 1 = blocked
                        break;
                    }
                }

                if (c != start.x ){
                    if (board[start.y][c] == nullptr or *board[start.y][c] != 'o')
                        seg1 = false; //seg 1 = blocked at column c
                }

            }
            // segment 2 (seg 2) moving vertically to the correct row
            {
                unsigned int minY, maxY;
                if (start.y < destination.y) {
                    minY = start.y;
                    maxY = destination.y;
                } else {
                    minY = destination.y;
                    maxY = start.y;
                }
                for (unsigned int y = minY + 1; y < maxY; y++) {
                    if (board[y][c] == nullptr or *board[y][c] != 'o') {
                        seg2 = false; //seg 2 = blocked
                        break;
                    }
                }

            }
            // segment 3 (seg 3) moving horizontally to the correct column (if needed)
            {
                unsigned int minX, maxX;
                if (c < destination.x) {
                    minX = c;
                    maxX = destination.x;
                } else {
                    minX = destination.x;
                    maxX = c;
                }
                for (unsigned int x = minX + 1; x < maxX; x++) {
                    if (board[destination.y][x] == nullptr or *board[destination.y][x] != 'o') {
                        seg3 = false; //seg 3 = blocked
                        break;
                    }
                }

                if (c != destination.x ){
                    if (board[destination.y][c] == nullptr or *board[destination.y][c] != 'o')
                        seg3 = false; //seg 3 = blocked at column c
                }
            }
            if (seg1 && seg2 && seg3) {
                found = true;
                break;
            }
        }
        if (!found)
            return false;
    }

    // move the button and make the previous spot an empty spot
    board[destination.y][destination.x] = std::move(board[start.y][start.x]);
    board[start.y][start.x] = make_unique<char>('o');

    return true;
}
