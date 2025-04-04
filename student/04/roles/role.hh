#ifndef ROLE_HH
#define ROLE_HH
#include <ostream>
using namespace std;
class Role
{
public:
    // Constructor
    Role(int from_year);

    // Destructor
    virtual ~Role();

    // Prints the role in the format:
    // Role started at <from_year_>
    /*virtual*/ void print(ostream& output) const;

private:
    int from_year_;
};

#endif // ROLE_HH
