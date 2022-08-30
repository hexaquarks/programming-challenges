#include <bits/stdc++.h>
using namespace std;

int main()
{
    string in, out = "h";
    cin >> in;
    
    int es = in.size() - 2;
    while (es--) out += "ee";
    out += 'y';
    
    cout << out << endl;
    return 0;
}