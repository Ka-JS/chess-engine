#include "shape.hh"
#include "circle.hh"
#include "rectangle.hh"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

using namespace std;

// Splits the given string into several strings, by using the given delimiter
// as a separator.
// Returns the splitted string as a vector such that each string part is an
// element of the vector.
// User can specify if empty parts will be ignored or not.
vector<string> split(const string& str, const char delimiter,
                     bool ignore_empty = false)
{
    vector<string> result;
    string tmp = str;

    while(tmp.find(delimiter) != string::npos)
    {
        string word = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
        if(not (ignore_empty and word.empty()))
        {
            result.push_back(word);
        }

    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

// Goes through the given vector of Shapes and prints each element
// (by calling their print functions).
void print_shapes(vector<shared_ptr<Shape>> shapes)
{
    int index = 1;
    for (auto& shape : shapes)
    {
        shape->print(index++);
        cout << endl;
    }
}

int main()
{
    cout << "Enter file name: ";
    string file_name = "";
    getline(cin, file_name);
    ifstream file(file_name);
    if(not file)
    {
        cout << "File not found" << endl;
        return EXIT_FAILURE;
    }
    string line = "";

    vector<shared_ptr<Shape>> shapes;

    // Goes through the input file line by line and splits each line.
    // Based on the content of each line, creates either a Circle
    // or a Rectangle, and pushes the shape to the vector shapes.
    while(getline(file, line))
    {
        auto parts = split(line, ' ', true);
        if (parts.size() < 2)
        {
            continue;
        }
        char color = parts.at(0)[0];
        try {
            if (parts.size() == 2) {
                double radius = stod(parts.at(1));
                shapes.push_back(make_shared<Circle>(color, radius));
            } else if (parts.size() == 3) {
                double width = stod(parts.at(1));
                double height = stod(parts.at(2));
                shapes.push_back(make_shared<Rectangle>(color, width, height));
            }
        } catch (...) {
            continue;
        }

    }
    print_shapes(shapes);
    return 0;
}
