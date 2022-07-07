#include <vector>


/* My solution - Better than 20 % */
int getBits(int num)
{
    int count = 0;
    while (num)
    {  
        count += num & 1;
        num >>= 1;
    }
    return count;
}
vector<int> solve(vector<int>& nums) 
{
    auto f = [](const int a, const int b)
    { 
        if (getBits(a) == getBits(b)) return a < b;
        else { return getBits(a) < getBits(b); };
    }; 

    std::sort(nums.begin(), nums.end(), f);
    return nums;
}

/* Accepted solution */
vector<int> solve(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int a, int b) {
        int ab = __builtin_popcount(a);
        int bb = __builtin_popcount(b);
        if (ab == bb) return a < b;
        return ab < bb;
    });
    return nums;
}