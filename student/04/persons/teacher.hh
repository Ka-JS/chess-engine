#ifndef TEACHER_HH
#define TEACHER_HH
#include "person.hh"
#include <set>
using namespace std;

class Teacher: public Person
{
public:
    Teacher(const string& name, int age, const string office_num);
    virtual ~Teacher();

    void change_room(const string& new_room);
    void add_new_course(const string& course);
    void remove_course(const string& course);
    void print(ostream& output) const;
private:
    string office_num_;
    set<string> responsibilities_;
};

#endif // TEACHER_HH
