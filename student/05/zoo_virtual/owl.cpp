#include "owl.hh"

Owl::Owl()
{
}

Owl::~Owl()
{
}

void Owl::vocalize(std::ostream& output) const {
    output << "Huu huu!" << std::endl;
}
