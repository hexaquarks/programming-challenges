#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, pair<int, int>> model{
        {'A', make_pair(11, 11)},
        {'K', make_pair(4, 4)},
        {'Q', make_pair(3, 3)},
        {'J', make_pair(20, 2)},
        {'T', make_pair(10, 10)},
        {'9', make_pair(14, 0)},
        {'8', make_pair(0, 0)},
        {'7', make_pair(0, 0)}
    };
    int n, N, ans = 0;
    char S;
    cin >> n >> S;
    N = 4 * n;
    
    while (N--)
    {
        string card;
        cin >> card;
        
        pair<int, int> val = model[card[0]];
        ans += card[1] == S ? val.first : val.second;
    }
    cout << ans;
    return 0;
}