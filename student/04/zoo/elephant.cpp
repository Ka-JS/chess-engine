#include "elephant.hh"


Elephant::Elephant(): Mammal()
{
}

Elephant::~Elephant(){}

void Elephant::trumpet(std::ostream& output) const{
    output << "Baraag baraag!" << std::endl;
}
