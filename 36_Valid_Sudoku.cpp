#include <vector>
#include <set>

using namespace std;

class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        vector<set<int>> cols(9), rows(9), blocks(9);
        // std::set::count(x) is a function that counts the number
        // of times a value x is present in the set, it can only return 
        // 1 or 0 as the set elements are unique by definitin
        
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                int val = board[i][j] - '0'; // this converts a 256 char to an int
                if (rows[i].count(val) || cols[j].count(val) ||
                    blocks[(i/3)*3 + j/3].count(val))
                {
                    // to find the k^th box given i in [0,8] and j in [0,8], 
                    // there exists the shortcut (i/3)*3 + (j/3). This trick 
                    // holds here since for any (i,j) pair there is a unique 
                    // element mapped within K = {k_0,...,k_8}.
                    return false;
                }
            }    
        }
        
        return true; 
    }
};