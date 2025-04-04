#ifndef PROGRAMMER_HH
#define PROGRAMMER_HH
#include "role.hh"
#include <set>
#include <string>

class Programmer: public Role
{
public:
    Programmer(int from_year);
    virtual ~Programmer();

    void add_skill(const string& skill);
    void print(ostream& output) const;

private:
    set<string> skills_;
};

#endif // PROGRAMMER_HH
