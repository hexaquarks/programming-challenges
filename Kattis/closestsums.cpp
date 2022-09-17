#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

unordered_map<string, int> mem;

int solve(vector<int>& v, int val)
{
    int closest = v[0] + v[1];
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = i + 1; j < v.size(); ++j)
        {
            int sum = v[i] + v[j];
            int diff = abs(val - sum);
            if (diff < abs(val - closest)) closest = sum;
        }
    }
    return closest;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    
    int n, caseN = 1;
    while (cin >> n)
    {
        cout << "Case " << caseN << ":" << endl;
        vector<int> v(n);
        int i = 0;
        while (n--) 
        {
            cin >> v[i];
            ++i;
        }
        
        int m;
        cin >> m;
        while (m--) 
        {
            int val;
            cin >> val;
            cout << "Closest sum to " << val << " is " << solve(v, val) << ".";
            cout << endl;
        }
        ++caseN;
    }
    return 0;
}