#include "rockpaperscissors.hh"
#include <iostream>

using namespace std;

RockPaperScissors::RockPaperScissors(unsigned int rounds): BaseGame(rounds)
{
}

RockPaperScissors::~RockPaperScissors()
{

}

void RockPaperScissors::printGameName() const
{
    cout << "Rock-Paper-Scissors Game" << endl;
}

unsigned int RockPaperScissors::roundWinner(const std::string &word1, const std::string &word2) const
{
    const string validWord[3] = {"rock", "paper", "scissors"};
    bool isValid1 = (word1 == validWord[0] or word1 == validWord[1] or word1 == validWord[2]);
    bool isValid2 = (word2 == validWord[0] or word2 == validWord[1] or word2 == validWord[2]);
    if (!isValid1 and !isValid2)
    {
        return 0;
    }
    if (!isValid1)
    {
        return 2;
    }
    if (!isValid2)
    {
        return 1;
    }
    if (word1 == word2)
        return 0;
    if ((word1 == "rock" and word2 == "scissors") or
        (word1 == "scissors" and word2 == "paper") or
        (word1 == "paper" and word2 == "rock"))
    {
        return 1;
    }
    return 2;
}
