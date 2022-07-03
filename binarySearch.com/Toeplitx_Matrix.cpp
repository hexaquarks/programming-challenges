#include <vector>

using namespace std;

/* My solution - faster than 100% */
bool solve(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    if (n == 0) return false;
    int m = matrix[0].size();
    if (m == 0) return false;

    for (int i = n - 2; ~i; --i)
    {
        int currVal = matrix[i][0];
        int k1 = i, k2 = 0;
        while (k1 < n && k2 < m)
        {
            if (matrix[k1][k2] != currVal) return false;
            else { ++k1; ++k2; }
        }
    }

    for (int j = n - 2; ~j; --j)
    {
        int currVal = matrix[0][j];
        int k1 = 0, k2 = j;
        while (k1 < n && k2 < m)
        {
            if (matrix[k1][k2] != currVal) return false;
            else { ++k1; ++k2; }
        }
    }

    return true;
}

/* Simpler solution - faster than 100% */
bool solve(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size() - 1; i++) {
        for (int j = 0; j < matrix[i].size() - 1; j++) {
            if (matrix[i][j] != matrix[i + 1][j + 1]) return false;
        }
    }
    return true;
}