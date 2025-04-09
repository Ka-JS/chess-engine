#include "circle.hh"

const double PI = 3.14159;


Circle::Circle(char color, double radius)
    : Shape(color), radius_(radius)
{

}

Circle::~Circle()
{

}

double Circle::area() const
{
    return PI*radius_*radius_;
}

double Circle::circumference() const
{
    return 2*PI*radius_;
}

void Circle::print(int running_number) const
{
    Shape::print(running_number);
    cout << COLOR_NAMES.at(get_color()) << " circle with radius " << radius_ << endl;
    cout << "Area: " << area() << endl;
    cout << "Circumference: " << circumference() << endl;
}
