class Solution {
public:
    vector<vector<int>> ans{};
    map<vector<int>, bool> mem{};

    void backtrack(vector<int>& candidates, pair<vector<int>, int>& curr, int target)
    {
        vector<int> s(curr.first.begin(), curr.first.end());
        sort(s.begin(), s.end());
        if (mem[s]) return;
        mem[s] = true;

        if (curr.second == target) {
            ans.push_back(curr.first);
            return;
        } else if (curr.second > target) {
            return;   
        } else {
            for (int val : candidates) {
                curr.first.push_back(val);
                curr.second += val;
                backtrack(candidates, curr, target);

                int last = curr.first.back();
                curr.first.pop_back();
                curr.second -= last;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        pair<vector<int>, int> curr;
        backtrack(candidates, curr, target);
        return ans;
    }
};