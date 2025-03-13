#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

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

double mean(const string& input)  // Don't change the function definition!
{
    // Pilkotaan syöte välilyöntien kohdalta.
    vector<string> tokens = split(input, ' ', true);

    // Jos lukuja ei ole, heitetään domain_error.
    if(tokens.empty()) {
        throw domain_error("domain_error: No numbers");
    }

    double sum = 0;
    int count = 0;

    // Yritetään muuntaa jokainen token double-arvoksi.
    for(const auto& token : tokens) {
        try {
            double value = stod(token);
            sum += value;
            count++;
        }
        catch(const invalid_argument&) {
            // Jos muunnos epäonnistuu, heitetään invalid_argument.
            throw invalid_argument("invalid_argument: stod");
        }
    }

    return sum / count;
}


// Don't remove! Needed for tests.
#ifndef MEAN_TEST
// Don't remove! Needed for tests.
// Main function
int main()
{
    cout << "Enter numbers: ";

    string input;
    // Luetaan koko rivi käyttäjän syötteestä
    getline(cin, input);

    try {
        double avg = mean(input);
        cout << "Mean: " << avg<< endl ;
    }
    catch(const invalid_argument& e) {
        cout << e.what()<< endl ;
    }
    catch(const domain_error& e) {
        cout << e.what()<< endl ;
    }

    return 0;
}
// Don't remove! Needed for tests.
#endif // MEAN_TEST
// Don't remove! Needed for tests.
