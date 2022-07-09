#include <vector>

using namespace std;

/* My solutin - Faster than 93% of submissions */
int solve(vector<int>& prices) 
{
    int n = prices.size();
    if (n == 0 || n == 1) return 0;

    int profit = 0;
    int curr = prices[0];

    for (int i = 1; i < n; ++i)   
    {
        if (prices[i] > curr)
        {
            profit = max(profit, prices[i] - curr);
        }
        if (prices[i] < curr) curr = prices[i];
    }
    return profit;
}

/* Cleaner accepted solution */
int solve(vector<int>& prices) {
    int profit = 0;
    int low = INT_MAX;

    for (auto x : prices) {
        low = min(low, x);

        profit = max(profit, x - low);
    }
    return profit;
}
