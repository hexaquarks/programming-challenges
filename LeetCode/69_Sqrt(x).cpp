class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x >= 1 && x <= 3) return 1;
        long long i = 1;
        for (; i <= x / 2; ++i) {
            if (i * i == x) return i;
            else if (i * i > x) return i - 1;
        }
        return i - 1;
    }
};