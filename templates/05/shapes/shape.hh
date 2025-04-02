#ifndef SHAPE_HH
#define SHAPE_HH

#include <string>
#include <map>

enum Color{RED, BLUE, YELLOW, GREEN};

const std::map<char, Color> COLOR_CODES = {{'r', RED},
                                           {'R', RED},
                                           {'b', BLUE},
                                           {'B', BLUE},
                                           {'y', YELLOW},
                                           {'Y', YELLOW},
                                           {'g', GREEN},
                                           {'G', GREEN}};

const std::map<Color, std::string> COLOR_NAMES = {{RED, "Red"},
                                                  {BLUE, "Blue"},
                                                  {YELLOW, "Yellow"},
                                                  {GREEN, "Green"}};

class Shape
{
public:
    Shape(char color);
    virtual ~Shape();
    void paint(char color);

    // TODO Add missing functions here

private:
    Color color_;
};

#endif // SHAPE_HH

