class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        else if (n == 3) return 3;
        int prev1 = 1, prev2 = 2, curr = prev1 + prev2 + 1;
        for (int i = 5; i <= n; ++i) {
            prev1 = prev2;
            prev2 = curr;
            curr = prev1 + prev2 + 1;
        }
        return curr + 1;
    }
};