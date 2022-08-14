#include <vector>
using namespace std;

class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> mem(m + 1, vector(n + 1, 0));
        
        mem[1][1] = 1;
        
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i == 1 && j == 1) continue;
                mem[i][j] = mem[i - 1][j] + mem[i][j - 1];
            }
        }
        
        return mem[m][n];
    }
};