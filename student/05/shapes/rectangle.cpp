#include "rectangle.hh"

Rectangle::Rectangle(char color, double width, double height)
          : Shape(color), width_(width), height_(height)
{

}

Rectangle::~Rectangle()
{

}

double Rectangle::area() const
{
    return width_ * height_;
}

double Rectangle::circumference() const
{
    return 2 * (width_ + height_);
}

void Rectangle::print(int running_number) const
{
    Shape::print(running_number);
    cout << COLOR_NAMES.at(get_color()) << " rectangle with width " << width_
              << " and height " << height_ << endl;
    cout << "Area: " << area() << endl;
    cout << "Circumference: " << circumference() << endl;
}
