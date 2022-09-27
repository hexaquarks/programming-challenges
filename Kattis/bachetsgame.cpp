#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

void computeDP(vector<bool>& dp, vector<int>& v, int i)
{
    for (const int val : v)
    {
        if (i < val) continue;
        if (!dp[i - val]) { dp[i] = true; break; }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> v;
        vector<bool> dp(n, false);
        
        while (m--)
        {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        for (int i = 1; i <= n; ++i) computeDP(dp, v, i);

        cout << (dp[n] ? "Stan wins" : "Ollie wins") << endl;
    }
    return 0;
}

// if I can take 1 or 3 and there are :
// 1 : lose
// 2 : win
// 3 : lose (because if he takes 1 then case 2 (loss) )
// 4 : win (case 3 + case 1)
// 5 : loss
// 6 : win