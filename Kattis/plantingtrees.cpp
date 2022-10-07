#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    
    int n;
    cin >> n;
    int nn = n;
    vector<int> v;
    while (n--)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.rbegin(), v.rend());
    
    int curr = v[0];
    for (int i = 1; i < nn; ++i)
    {
        --curr;
        curr = max(curr, v[i]);
    }
    cout << nn + curr + 1;
    
    return 0;
}