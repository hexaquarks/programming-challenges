#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return;
        
        vector<bool> rows(m, false), cols(n, false);
        
        // Preprocess to initialize the boolean matrix
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    rows[i] = false;
                    cols[j] = false;   
                }
            }
        }
        
        for (int i = 0; i < m; ++i)
        {
            if (rows[i])
            {
                for (int j = 0; j < n; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for (int i = 0; i < n; ++i)
        {
            if (cols[i])
            {
                for (int j = 0; j < m; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};