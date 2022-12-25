#include <bits/stdc++.h>
using namespace std;

int calcNum(char c) {
  return c - (islower(c) ? 'a' - 1 : 'A' - 27);
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
        
        
        unordered_map<char, int> m;
        int i = 0;
        char letter;
        for (; i < line.size() / 2; ++i) ++m[line[i]];
        for (; i < line.size(); ++i) {
            if (m[line[i]]) {
                letter = line[i];
                break;
            } 
        }
        int num = calcNum(letter);
        tot1 += num;
        
        /* Part 2 */
        triplet.push_back(line);
        if (triplet.size() == 3)
        {
            unordered_map<char, int> m1, m2;
            for (int i = 0; i < triplet[0].size(); ++i) ++m1[triplet[0][i]];
            for (int i = 0; i < triplet[1].size(); ++i) ++m2[triplet[1][i]];
            for (int i = 0; i < triplet[2].size(); ++i) { 
                if (m1[triplet[2][i]] && m2[triplet[2][i]])
                {
                    letter = triplet[2][i];
                    break;
                }
            }
            int num = calcNum(letter);
            tot2 += num;
            triplet.clear();
        }
    }
    cout << "tot1 is : " << tot1 << endl;
    cout << "tot2 is : " << tot2 << endl;
    return 0;
}
