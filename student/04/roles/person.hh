#ifndef PERSON_HH
#define PERSON_HH

#include "role.hh"
#include <string>
#include <vector>
#include <ostream>

class Person
{
public:
    // Constructor
    Person(const string& name);

    // Destructor
    virtual ~Person();

    // Adds a new role for the person
    void add_role(Role* role);

    // Prints the roles
    void print(ostream& output) const;

    // Prints the name
    void print_name(ostream& output) const;

private:
    string name_;
    vector<Role*> roles_;
};

#endif // PERSON_HH
