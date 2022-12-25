#include <vector>
#include <algorithm>

using namespace std;

/* My solution - Faster than 45% */
int solve(vector<int>& nums, int k) 
{
    int n = nums.size();
    if (n == 0) return 0;

    auto f = [](const int first, const int second) { return abs(first) > abs(second); };
    std::sort(nums.begin(), nums.end(), f);

    int sum = 0, minVal = std::numeric_limits<int>::max();
    for (int i = 0; i < n; ++i)
    {
        int val = nums[i];
        if (val < 0 && k > 0)
        {
            sum += val * -1;
            --k;
        }
        else 
        {
            sum += val;
        }
    }

    if (k != 0)
    {
        if (k % 2 != 0) sum += (nums[n - 1] >= 0 ? -2 : 2) * nums[n - 1];
    }

    return sum;
}

/* Accepted better solution */
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());
        while (K--) {
            int x = pq.top();
            pq.pop();

            pq.push(-1 * x);
        }
        int res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
