#include "sudoku.hh"

Sudoku::Sudoku()
{
    // tehää 9x9 ruudukko
    grid = vector<vector<char>>(SIZE, vector<char>(SIZE, ' '));
}

void Sudoku::set(int i, int j, char c)
{
    if (i < 0 or i >= SIZE or j < 0 or j >= SIZE) {
        cout << "Trying to access illegal cell (" << i << ", " << j << ")!" << endl;
        return;
    }
    if (c != ' ' and (c < '1' or c > '9')) {
        cout << "Trying to set illegal character " << c << " to (" << i << ", " << j << ")!" << endl;
        return;
    }
    grid[i][j] = c;
}

bool Sudoku::check()
{
    // Tarkista rivit
    for (int i = 0; i < SIZE; i++) {
        int freq[10] = {0};
        for (int j = 0; j < SIZE; j++) {
            char ch = grid[i][j];
            if (ch != ' ') {
                int d = ch - '0';
                freq[d]++;
            }
        }
        for (int d = 1; d <= 9; d++) {
            if (freq[d] > 1) {
                cout << "Row " << i << " has multiple " << d << "'s!" << endl;
                return false;
            }
        }
    }

    // Tarkista sarakkeet
    for (int j = 0; j < SIZE; j++) {
        int freq[10] = {0};
        for (int i = 0; i < SIZE; i++) {
            char ch = grid[i][j];
            if (ch != ' ') {
                int d = ch - '0';
                freq[d]++;
            }
        }
        for (int d = 1; d <= 9; d++) {
            if (freq[d] > 1) {
                cout << "Column " << j << " has multiple " << d << "'s!" << endl;
                return false;
            }
        }
    }

    // Tarkista 3x3 lohkot
    for (int br = 0; br < BLOCK_SIZE; br++) {
        for (int bc = 0; bc < BLOCK_SIZE; bc++) {
            int freq[10] = {0};
            int startRow = br * BLOCK_SIZE;
            int startCol = bc * BLOCK_SIZE;
            for (int i = startRow; i < startRow + BLOCK_SIZE; i++) {
                for (int j = startCol; j < startCol + BLOCK_SIZE; j++) {
                    char ch = grid[i][j];
                    if (ch != ' ') {
                        int d = ch - '0';
                        freq[d]++;
                    }
                }
            }
            for (int d = 1; d <= 9; d++) {
                if (freq[d] > 1) {
                    cout << "Block at (" << startRow << ", " << startCol << ") has multiple " << d << "'s!" << endl;
                    return false;
                }
            }
        }
    }

    return true;
}

void Sudoku::print()
{
    // tehöö border ja rowseparator
    const string border = "#####################################";
    const string rowSeparator = "#---+---+---#---+---+---#---+---+---#";

    // tulostetaan yläreuna
    cout << border << endl;

    // Tulostetaan ruudukon rivit
    for (int i = 0; i < SIZE; i++) {
        cout << "#";
        for (int j = 0; j < SIZE; j++) {
            cout << " " << grid[i][j] << " ";
            // Tulostetaan pystyrivien erotin:
            if ((j + 1) % BLOCK_SIZE == 0)
                cout << "#";
            else
                cout << "|";
        }
        cout << endl;

        if ( (i % BLOCK_SIZE) != BLOCK_SIZE - 1 )
            cout << rowSeparator << endl;
        else if (i != SIZE - 1)
            cout << border << endl;
    }

    // Tulostetaan alareuna
    cout << border << endl;
}
