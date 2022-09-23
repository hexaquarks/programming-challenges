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
    vector<int> v;
    long long lower = 0;
    
    function<void(int, int)> backtrack = [&](long long tot, int idx)
    {
        if (tot >= 200) return;
        lower += tot;
        
        for (int i = idx; i < v.size(); ++i)
        {
            backtrack(tot + v[i], i + 1);
        }
    };
    
    while (n--)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    backtrack(0, 0);
    
    long long total = (long long)(pow(2, v.size() - 1)) * accumulate(v.begin(), v.end(), 0);
    cout << (total - lower) << endl;
    return 0;
}