#include "programmer.hh"

Programmer::Programmer(int from_year) : Role(from_year)
{

}

Programmer::~Programmer()
{

}

void Programmer::add_skill(const string& skill) {
    skills_.insert(skill);
}

void Programmer::print(ostream& output) const {
    if (skills_.empty()) {
        output << "No skills" << endl;
    } else {
        output << "Skills:";
        for (const auto& skill : skills_) {
            output << " " << skill;
        }
        output << endl;
    }
}
