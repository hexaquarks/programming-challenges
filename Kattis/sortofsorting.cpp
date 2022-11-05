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

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int main()
{
    IOS;
    int n; 
    while (cin >> n && n)
    {
        vector<string> names(n);
        for (int i = 0; i < n; ++i) cin >> names[i];
        
        auto l = [&](const string& a, const string& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        };
        
        stable_sort(names.begin(), names.end(), l);
        
        for (const string& s : names) cout << s << endl;
        cout << endl;
    }
    
    return 0;
}