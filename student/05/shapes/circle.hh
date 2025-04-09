#ifndef CIRCLE_HH
#define CIRCLE_HH
#include "shape.hh"

class Circle : public Shape
{
public:
    Circle(char color, double radius);
    virtual ~Circle();

    virtual double area() const override;
    virtual double circumference() const override;
    virtual void print(int running_number) const override;

private:
    double radius_;
};

#endif // CIRCLE_HH
