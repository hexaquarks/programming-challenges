#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double isInCircle(int x1, int y1, int x2, int y2, int r)
    {
        return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)) <= r;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans{};
        for (const vector<int> query : queries)
        {
            int x2 = query[0], y2 = query[1], r = query[2];
            int sum = 0;
            for (const vector<int>& point : points)
            {
                int x1 = point[0], y1 = point[1];
                if (isInCircle(x1, y1, x2, y2, r)) ++sum;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};