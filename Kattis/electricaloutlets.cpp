#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    cin >> n;
    
    while (n--)
    {
        int k, temp;
        cin >> k; 
        int tot = 0;
        temp = k;
        
        while (temp--)
        {
            int o;
            cin >> o;
            
            tot += o;
            // nb of outlets in each power strip
        }
        tot -= (k - 1);
        cout << tot << endl;
    }
    return 0;
}