#include <bits/stdc++.h>
using namespace std;

int main()
{   
    ios::sync_with_stdio(false);
    
    int n; 
    cin >> n;
    
    int i = 1;
    while (n--)
    {
        string word;
        cin >> word;
        if (i % 2 != 0) cout << word << endl;
        ++i;
    }
    return 0;
}