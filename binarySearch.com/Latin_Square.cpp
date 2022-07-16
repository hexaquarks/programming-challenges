#include <vector>
#include <unordered_set>

using namespace std;

/* My solution - Faster than 100% */
bool solve(vector<vector<string>>& matrix) 
{
    int n = matrix.size();
    if (n == 0) return false;

    vector<unordered_set<string>> mem(n, unordered_set<string>());
    unordered_set<string> uniqueChars;

    for (int i = 0; i < n; ++i)
    {
        unordered_set<string> row(matrix[i].begin(), matrix[i].end());
        if (row.size() < n) return false;

        for (int j = 0; j < n; ++j)
        {
            unordered_set<string>& column = mem[j];
            string val = matrix[i][j];

            if (column.find(val) != column.end()) return false;
            else column.insert(val);

            uniqueChars.insert(val);
        }
    }
    if (uniqueChars.size() != n) return false;
    return true;
}

/* Cleaner solution using bit manipulation */
bool solve(vector<vector<string>>& matrix) {
    int l = 0;
    for (int i = 0; i < matrix.size(); i++) {
        int x = 0;
        int y = 0;
        for (int j = 0; j < matrix[i].size(); j++) {
            if (x & (1 << (matrix[i][j][0] - 'a'))) return false;
            if (y & (1 << (matrix[j][i][0] - 'a'))) return false;
            x |= (1 << (matrix[i][j][0] - 'a'));
            y |= (1 << (matrix[j][i][0] - 'a'));
        }
        if (x != y) return false;
        if (i != 0 && x != l) return false;
        l = x;
    }
    return true;
}