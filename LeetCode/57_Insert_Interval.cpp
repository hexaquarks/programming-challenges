class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        for(vector<int>& v : intervals){
            if (v[1] < newInterval[0]) {
                ans.push_back(v);
            } else if (newInterval[1] < v[0]) {
                ans.push_back(newInterval);
                newInterval = v;
            } else {
                newInterval[0] = min(v[0], newInterval[0]);
                newInterval[1] = max(v[1], newInterval[1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};