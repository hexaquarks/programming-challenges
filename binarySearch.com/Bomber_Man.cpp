#include <vector>
#include <numeirc>

using namespace std;

/* My solution - faster than 30% */
int solve(vector<vector<int>>& matrix) 
{
    vector<bool> rows(matrix.size(), false);
    vector<bool> cols(matrix[0].size(), false);

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == 1)
            {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == 0)
            {
                if (!rows[i] && !cols[j]) ++count;
            }
        }
    }
    return count;
}

/* Much better solution */
int solve(vector<vector<int>>& matrix) {
    int M = matrix.size(), N = matrix[0].size();
    vector<int> rows(M, 1), cols(N, 1);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            if (matrix[i][j]) rows[i] = cols[j] = 0;
    }
    return accumulate(rows.begin(), rows.end(), 0) * accumulate(cols.begin(), cols.end(), 0);
}