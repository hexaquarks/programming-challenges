#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int atBats = n, numerator = 0;
    double ans;
    
    while (n--)
    {
        int k;
        cin >> k;
        if (k == -1) --atBats;
        else numerator += k;
    }

    cout <<  ((double)numerator / (double)atBats) << endl;
    return 0;
}