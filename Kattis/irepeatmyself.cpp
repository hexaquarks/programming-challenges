#include <bits/stdc++.h>
using namespace std;

#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define f first
#define s second
#define endl "\n"

int main()
{
    IOS;
    int n;
    cin >> n;
    cin.clear(); cin.ignore();
    
    while (n--)
    {
        string line;
        getline(cin, line);
        // sliding window
        int l = 0, r;
        for (r = 1; r < line.size(); ++r)
        {
            if (line[l] == line[r]) ++l;
            else { r -= l; l = 0; }
        }
        cout << r - l << endl;
    }
    return 0;
}