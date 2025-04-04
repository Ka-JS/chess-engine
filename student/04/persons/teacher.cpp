#include "teacher.hh"

Teacher::Teacher(const string &name, int age, const string office_num):
                Person(name, age), office_num_(office_num)
{
    cout << "Teacher created: " << name_ << endl;

}

Teacher::~Teacher()
{
    cout << "Teacher destructed: " << name_ << endl;
}

void Teacher::change_room(const string &new_room)
{
    office_num_ = new_room;
}

void Teacher::add_new_course(const string &course)
{
    responsibilities_.insert(course);
}

void Teacher::remove_course(const string &course)
{
    responsibilities_.erase(course);
}

void Teacher::print(ostream &output) const
{
    Person::print(output);
    output << "*** " << office_num_ << ": ";
    if (responsibilities_.empty()) {
        output << "No responsibilities" << endl;
    } else {
        auto it = responsibilities_.begin();
        while (it != responsibilities_.end()) {
            output << *it;
            ++it;
            if (it != responsibilities_.end()) {
                output << ", ";
            }
        }
        output << endl;
    }
}
