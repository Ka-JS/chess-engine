#ifndef SHAPE_HH
#define SHAPE_HH
using namespace std;
#include <iostream>
#include <string>
#include <map>

enum Color{RED, BLUE, YELLOW, GREEN};

const map<char, Color> COLOR_CODES = {{'r', RED},
                                           {'R', RED},
                                           {'b', BLUE},
                                           {'B', BLUE},
                                           {'y', YELLOW},
                                           {'Y', YELLOW},
                                           {'g', GREEN},
                                           {'G', GREEN}};

const map<Color, string> COLOR_NAMES = {{RED, "Red"},
                                                  {BLUE, "Blue"},
                                                  {YELLOW, "Yellow"},
                                                  {GREEN, "Green"}};

class Shape
{
public:
    Shape(char color);
    virtual ~Shape();
    void paint(char color);

    Color get_color() const;

    virtual double area() const = 0;
    virtual double circumference() const = 0;

    virtual void print(int running_number) const;

private:
    Color color_;
};

#endif // SHAPE_HH

