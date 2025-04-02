#include "mostvowels.hh"
#include <iostream>

using namespace std;

MostVowels::MostVowels(unsigned int rounds) : BaseGame(rounds)
{
}

MostVowels::~MostVowels()
{
}

void MostVowels::printGameName() const
{
    cout << "Most Vowels Game" << endl;
}

unsigned int MostVowels::roundWinner(const std::string &word1, const std::string &word2) const
{
    auto CountVowels = [](const string& word){
        int count = 0;
        const string vowels = "aeiouyAEIOUY";
        for (auto c : word){
            if (vowels.find(c) != string::npos){
                ++count;
            }
        }
        return count;
    };
    int vowels1 = CountVowels(word1);
    int vowels2 = CountVowels(word2);
    if (vowels1 > vowels2)
    {
        return 1;
    }
    else if (vowels1 < vowels2)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
