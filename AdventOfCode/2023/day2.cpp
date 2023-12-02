#include <bits/stdc++.h>
using namespace std;

namespace util 
{
vector<string> split(string s, string delimiter) 
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back (s.substr(pos_start));
    return res;
}
}

namespace 
{

void computeMaximums(const string& set, int& maxRed, int& maxBlue, int& maxGreen)
{
    const vector<string> cubeValuePairs = util::split(set, ", ");
    for (const auto& cubeValuePair : cubeValuePairs) {
        const auto cubeValueSplit = util::split(cubeValuePair, " ");
        int value = stoi(cubeValueSplit[0]);  
        const string cube = cubeValueSplit[1];

        if (cube == "red") maxRed = max(maxRed, value);
        else if (cube == "blue") maxBlue = max(maxBlue, value);
        else if (cube == "green") maxGreen = max(maxGreen, value);
    }
}

bool is_set_possible(const string& set)
{
    int redValue = 0, blueValue = 0, greenValue = 0;

    const vector<string> cubeValuePairs = util::split(set, ", ");
    for (const auto& cubeValuePair : cubeValuePairs) {
        const auto cubeValueSplit = util::split(cubeValuePair, " ");
        int value = stoi(cubeValueSplit[0]);  
        const string cube = cubeValueSplit[1];

        if (cube == "red") redValue += value;
        else if (cube == "blue") blueValue += value;
        else if (cube == "green") greenValue += value;
    }

    return !(redValue > 12 || blueValue > 14 || greenValue > 13);
}
}

int computePartA(string& s) 
{  
    vector<string> split = util::split(s, ": ");
    const auto gameIdSplit = util::split(split[0], " ");
    int gameId = stoi(gameIdSplit[1]);
    bool isGamePossible = true;

    const auto sets = util::split(split[1], "; ");
    for (const auto& set : sets) {
        if (!is_set_possible(set)) {
            isGamePossible = false;
            break;
        }
    }

    return isGamePossible ? gameId : 0;
}

int computePartB(string& s) 
{  
    vector<string> split = util::split(s, ": ");
    const auto gameIdSplit = util::split(split[0], " ");
    const auto sets = util::split(split[1], "; ");

    int maxRed = 0, maxBlue = 0, maxGreen = 0;

    for (const string& set : sets) {
        computeMaximums(set, maxRed, maxBlue, maxGreen);
    }

    return maxBlue * maxRed * maxGreen;
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