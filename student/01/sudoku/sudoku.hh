#ifndef SUDOKU_HH
#define SUDOKU_HH

#include <iostream>
#include <vector>
using namespace std;

const int BLOCK_SIZE = 3;
const int SIZE = 3 * BLOCK_SIZE;

class Sudoku
{
public:
    Sudoku();
    void set(int i, int j, char c);
    bool check();
    void print();
private:
    vector<vector<char>> grid;
};

#endif // SUDOKU_HH
