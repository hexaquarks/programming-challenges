#include <bits/stdc++.h>
using namespace std;

int boxBlurAlgo(vector<vector<int>>& image, int x, int y)
{
    int sum = 0;
    for (int i = x - 1; i <= x + 1; ++i)
    {
        for (int j = y - 1; j <= y + 1; ++j)
        {
            sum += image[i][j];
        }
    }
    return sum;
}

vector<vector<int>> solution(vector<vector<int>> image) 
{
    int n = image.size(), m = image[0].size();
    vector<vector<int>> ans(n - 2, vector<int>(m - 2));
    for (int i = 1; i <= n - 2; ++i)
    {
        for (int j = 1; j <= m - 2; ++j)
        {
            ans[i - 1][j - 1] = floor(boxBlurAlgo(image, i, j) / 9);
        }
    }
    return ans; 
}
