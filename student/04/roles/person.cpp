#include "person.hh"
#include <iostream>

Person::Person(const std::string &name) : name_(name)
{
}

Person::~Person()
{

}

void Person::add_role(Role* role)
{
    roles_.push_back(role);
}

void Person::print(std::ostream &output) const
{
    for (const Role* role : roles_)
    {
        role->print(output);
    }
}

void Person::print_name(std::ostream &output) const
{
    output << name_ << std::endl;
}
