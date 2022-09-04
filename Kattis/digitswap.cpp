#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string s = to_string(n);
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}