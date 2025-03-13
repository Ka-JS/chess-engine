#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    cout << "Enter numbers: ";

    string input;
    getline(cin, input);

    if (input.empty()) {
        cout << "No input" << endl;
        return EXIT_FAILURE;
    }

    vector<double> numbers;
    stringstream ss(input);
    double num;

    while (ss >> num) {
        numbers.push_back(num);
    }

    if (!ss.eof()) {
        cout << "Not a double" << endl;
        return EXIT_FAILURE;
    }

    if (numbers.empty()) {
        cout << "No input" << endl;
        return EXIT_FAILURE;
    }

    sort(numbers.begin(), numbers.end());

    double median;
    size_t size = numbers.size();

    if (size % 2 == 1) {
        median = numbers[size / 2];
    } else {
        median = (numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;
    }

    cout << "Median: " << median << endl;
    return EXIT_SUCCESS;
}
