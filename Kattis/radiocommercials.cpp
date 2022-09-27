#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    int n, p;
    cin >> n >> p;
    
    vector<int> v; 
    while (n--) 
    { 
        int temp; cin >> temp;
        temp -= 20;
        v.push_back(temp);
    }
    
    long long maxProfit = numeric_limits<int>::min(), profit = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        profit += v[i];
        maxProfit = max(maxProfit, profit);
        if (profit < 0) profit = 0;
    }
    
    cout << maxProfit;
    return 0;
}

// if one student listens to a commercial +1 revenue