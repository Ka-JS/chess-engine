#include "role.hh"
#include <ostream>

Role::Role(int from_year) : from_year_(from_year) {}

Role::~Role() {}

void Role::print(ostream& output) const {
    output << "Role started at " << from_year_ << endl;
}
