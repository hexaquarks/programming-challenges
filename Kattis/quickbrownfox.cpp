#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    while (n--)
    {
        string s;
        getline(cin, s);
        
        vector<int> letters(26, -1);
        bool found = false;
        
        for (const char& c : s) 
        {
            const int val = tolower(c) - 'a'; 
            if (val >= 0 && val < 26) ++letters[val];
        }
        for (int i = 0; i < letters.size(); ++i)
        {
            if (letters[i] == -1) 
            {
                if (!found) 
                {
                    found = true;
                    cout << "missing ";
                }
                char c = static_cast<char>(i + 'a');
                cout << c;
            }
        }
        if (!found) cout << "pangram";
        cout << endl;
    }
    return 0;
}