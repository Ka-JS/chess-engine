#ifndef RECTANGLE_HH
#define RECTANGLE_HH
#include "shape.hh"

class Rectangle : public Shape
{
public:
    Rectangle(char color, double width, double height);
    virtual ~Rectangle();

    virtual double area() const override;
    virtual double circumference() const override;
    virtual void print(int running_number) const override;

private:
    double width_;
    double height_;
};

#endif // RECTANGLE_HH
