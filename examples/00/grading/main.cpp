#include <iostream>

using namespace std;

// The constant values below are valid at the beginning of the course.
// At the end of the course, if you use this program to calculate your total
// grade, check the values and update them to match those in Plussa, if needed.
const unsigned int MAX_P_POINTS_PER_PROJECT = 50;
const unsigned int MAX_P_POINTS = 2 * MAX_P_POINTS_PER_PROJECT;
const unsigned int MAX_CPP_POINTS = 500;
const unsigned int MAX_B_POINTS = 10;

// Minimum for the sum of points gathered from two projects.
const unsigned int MIN_P_POINTS = 40;

// Prints current constant value that are used in calculations
void print_constants()
{
    cout << "The program uses the following values for constants:" << endl;
    cout << "  MAX_P_POINTS:   " << MAX_P_POINTS << endl;
    cout << "  MAX_CPP_POINTS: " << MAX_CPP_POINTS << endl;
    cout << "  MAX_B_POINTS:   " << MAX_B_POINTS << endl;
    cout << "Update the values, if they do not match with those in Plussa.";
}

// Informs about invalid (too big) P, CPP, and B points.
// Returns true, if all these points are valid, otherwise returns false.
bool is_valid_points(unsigned int p1, unsigned int p2, unsigned int cpp,
                     unsigned int b)
{
    bool is_valid = true;
    if( p1 > MAX_P_POINTS_PER_PROJECT or p2 > MAX_P_POINTS_PER_PROJECT )
    {
        cout << "Impossible project points" << endl;
        is_valid = false;
    }
    if( cpp > MAX_CPP_POINTS )
    {
        cout << "Impossible exercise points" << endl;
        is_valid = false;
    }
    if( b > MAX_B_POINTS )
    {
        cout << "Impossible bonus points" << endl;
        is_valid = false;
    }
    return is_valid;
}

// Converts the given points to the total grade
unsigned int calculate_total_grade(unsigned int points)
{
    if( points < 500 ) { return 0; }
    if( points < 600 ) { return 1; }
    if( points < 700 ) { return 2; }
    if( points < 800 ) { return 3; }
    if( points < 900 ) { return 4; }
    return 5;
}

int main()
{
    print_constants();
    cout << endl << endl;
    unsigned int p1 = 0;
    unsigned int p2 = 0;
    unsigned int cpp = 0;
    unsigned int b = 0;
    cout << "Enter points from categories P1, P2, CPP, and B: ";
    cin >> p1;
    cin >> p2;
    cin >> cpp;
    cin >> b;

    if( is_valid_points(p1, p2, cpp, b) )
    {
        unsigned int total_points = 0;

        // Both projects must be done, sum of P points must be at least 40,
        // and at least half of the CPP points must be gathered.
        if( p1 > 1 and p2 > 1 and p1 + p2 >= MIN_P_POINTS and
            2 * cpp >= MAX_CPP_POINTS )
        {
            string exam = "";
            cout << "Exam passed (y/n): ";
            cin >> exam;
            if(exam == "y" or exam == "Y") // Exam must be passed
            {
                total_points = 5 * (p1 + p2) + cpp + b;
            }
        }
        cout << "Total grade: " << calculate_total_grade(total_points) << endl;
    }

    return 0;
}
