#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    int t;
    cin >> t;
    int iCase = 1;
    
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v1(n), v2(n);
        for (int i = 0; i < n; ++i) cin >> v1[i];
        for (int i = 0; i < n; ++i) cin >> v2[i];
        sort(v1.begin(), v1.end());
        sort(v2.rbegin(), v2.rend());
        
        long long result = inner_product(v1.begin(), v1.end(), v2.begin(),(long long) 0);
        
        cout << "Case #" << iCase << ": " << result << endl;
        ++iCase;
    }
    return 0;
}