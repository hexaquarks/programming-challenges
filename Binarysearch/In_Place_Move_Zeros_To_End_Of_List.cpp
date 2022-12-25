#include <vector>

using namespace std;

/* My solution */
vector<int> solve(vector<int>& nums) {
    vector<int> ans;

    int counter = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == 0) ++counter;
        else ans.push_back(nums[i]);
    }

    while (counter--)
    {
        ans.push_back(0);
    }

    return ans;
}

/* Faster solution */
vector<int> solve(vector<int>& nums) {
    int count = 0;

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            swap(nums[i], nums[count]);
            count++;
        }
    }

    return nums;
}