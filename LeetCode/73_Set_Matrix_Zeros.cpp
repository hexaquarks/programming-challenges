class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<bool>> skip(matrix.size(), vector<bool>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0 && !skip[i][j]) {
                    for (int k = 0; k < matrix.size(); ++k) {
                        if (matrix[k][j] != 0) {
                            matrix[k][j] = 0;
                            skip[k][j] = true;
                        }
                    }
                    for (int k = 0; k < matrix[0].size(); ++k) { 
                        if (matrix[i][k] != 0) {
                            matrix[i][k] = 0;
                            skip[i][k] = true;
                        }
                    }
                }
            }
        }
    }
}