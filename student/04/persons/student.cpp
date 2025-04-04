#include "student.hh"
using namespace std;

Student::Student(const string &name, int age, const string student_num):
                 Person(name, age), student_num_(student_num)
{
    cout << "Student created: " << name_ << endl;
}

Student::~Student()
{
    cout << "Student destructed: " << name_ << endl;

}

void Student::complete_course(const string &course)
{
    completed_courses_.push_back(course);

}

void Student::print(ostream &output) const
{
    Person::print(output);
    output << "+++ " << student_num_ << ": ";
    if (completed_courses_.empty()) {
        output << "No courses completed" << endl;
    } else {
        for (size_t i = 0; i < completed_courses_.size(); ++i) {
            output << completed_courses_[i];
            if (i < completed_courses_.size() - 1)
                output << ", ";
        }
        output << endl;
    }
}
