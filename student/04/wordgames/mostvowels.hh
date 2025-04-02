#ifndef MOSTVOWELS_HH
#define MOSTVOWELS_HH
#include "basegame.hh"
#include <string>


class MostVowels: public BaseGame
{
public:
    MostVowels(unsigned int rounds);
    virtual ~MostVowels();
    void printGameName() const;
    unsigned int roundWinner(const std::string& word1,
                             const std::string& word2) const;
private:
    unsigned int rounds_;
};

#endif // MOSTVOWELS_HH
