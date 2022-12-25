#include <bits/stdc++.h>
using namespace std;

vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

bool isWithin(int a1, int a2, int b1, int b2) {
    return (a1 >= b1 && a1 <= b2) && (a2 >= b1 && a2 <= b2);
}

bool isPartiallyWithin(int a1, int a2, int b1, int b2) {
    return (a1 >= b1 && a1 <= b2) || (a2 >= b1 && a2 <= b2);
}

int main()
{
    int tot1 = 0, tot2 = 0;
    vector<string> triplet;
    while (true)
    {
        string line;
        getline(cin, line);
        if (line == "") break;
        vector<string> pairs = split(line, ",");
        vector<string> p1 = split(pairs[0], "-"), p2 = split(pairs[1], "-");
        int a1 = stoi(p1[0]), a2 = stoi(p1[1]), b1 = stoi(p2[0]), b2 = stoi(p2[1]);
        if (isWithin(a1, a2, b1, b2) || isWithin(b1, b2, a1, a2)) ++tot1;
        if (isPartiallyWithin(a1, a2, b1, b2) || isPartiallyWithin(b1, b2, a1, a2)) ++tot2;
    }
    cout << "tot1 is : " << tot1 << endl;
    cout << "tot2 is : " << tot2 << endl;
    return 0;
}
