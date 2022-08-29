#include <vector>

using namespace std; 

int solution(vector<vector<int>> matrix) 
{
    if (matrix.size() == 0) return 0;
    if (matrix[0].size() == 0) return 0;
    
    int ans = 0;
    
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            int val = matrix[i][j];
            if (val != 0)
            {
                if (i > 0)
                {
                    bool found = false;
                    for (int k = i - 1; k >= 0; --k)
                    {
                        if (matrix[k][j] == 0) found = true;   
                    }
                    if (!found) ans += val;
                }
                else {
                    ans += val;
                }
            }
        }
    }
    return ans;
}
