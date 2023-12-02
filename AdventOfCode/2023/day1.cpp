#include <bits/stdc++.h>
using namespace std;

namespace 
{
vector<pair<string, string>> extendWithCompoundCases(const vector<pair<string, string>>& numbersAndDigits)
{
    vector<pair<string, string>> extendedNumbersAndDigits;

    for (const auto& [word1, digit1] : numbersAndDigits) 
    {
        for (const auto& [word2, digit2] : numbersAndDigits) 
        {
            if (word1 == word2) continue;

            if (word1.back() == word2[0]) {
                extendedNumbersAndDigits.push_back({
                        (word1.substr(0, word1.size()) + word2.substr(1, word2.size())),
                        (digit1 + digit2)
                    }
                );
            }
        }    
    }

    extendedNumbersAndDigits.insert(
        extendedNumbersAndDigits.end(),
        numbersAndDigits.begin(),
        numbersAndDigits.end());

    return extendedNumbersAndDigits;
}
}

int computePartA(string& s) 
{  
    int first, second;
    for (const char& c : s) {
        if (isdigit(c)) {
            first = c - '0';
            break;
        }
    }

    for (int i = s.size(); i >= 0; --i) {
        if (isdigit(s[i])) {
            second = s[i] - '0';
            break;
        }
    }

    return first * 10 + second;
}

int computePartB(string& s)
{
    const vector<pair<string, string>> numbersAndDigits {
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"},
    };

    const auto& extendedNumbersAndDigits = extendWithCompoundCases(numbersAndDigits);

    for (const auto& [number, digit] : extendedNumbersAndDigits) {
        bool needToReplaceAgain = true;
        while (needToReplaceAgain) {
            size_t foundIdx = s.find(number);
            if (foundIdx != string::npos) {
                s.replace(foundIdx, number.size(), digit);
                continue;
            }
            needToReplaceAgain = false;
        }
    }

    return computePartA(s);
}

int main()
{
    int totA = 0, totB = 0;
    while (true)
    {
        string s;
        getline(cin, s);
        if (s.empty()) break;

        totA += computePartA(s);
        totB += computePartB(s);
    }
    cout << totA << ", " << totB << endl;
    return 0;
}