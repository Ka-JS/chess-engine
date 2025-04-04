#ifndef STUDENT_HH
#define STUDENT_HH
#include "person.hh"
#include <vector>
using namespace std;

class Student: public Person
{
public:
    Student(const string& name, int age, const string student_num);
    virtual ~Student();

    void complete_course(const string& course);
    void print(ostream& output) const;

private:
    string student_num_;
    vector<string> completed_courses_;
};

#endif // STUDENT_HH
