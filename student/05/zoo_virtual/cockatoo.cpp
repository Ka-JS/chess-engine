#include "cockatoo.hh"

Cockatoo::Cockatoo(): Bird()
{

}

Cockatoo::~Cockatoo()
{

}

void Cockatoo::vocalize(std::ostream& output) const {
    output << "Lal laa la laa!" << std::endl;
}

