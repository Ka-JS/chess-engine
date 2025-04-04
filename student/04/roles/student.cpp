#include "student.hh"

Student::Student(int from_year, int student_number)
    : Role(from_year), student_number_(student_number)
{

}

Student::~Student()
{

}

void Student::print(ostream& output) const {
    output << "Student number: " << student_number_ << endl;
}
