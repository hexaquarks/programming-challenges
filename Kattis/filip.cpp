#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int a, b;
    cin >> a >> b;
    
    string as = to_string(a), bs = to_string(b);
    reverse(as.begin(), as.end());
    reverse(bs.begin(), bs.end());
    
    cout << ((as > bs) ? as : bs) << endl;

	return 0;
}