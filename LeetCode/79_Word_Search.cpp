class Solution {
public:
    bool ans = false;
    void search(vector<vector<char>>& board, string& word, int i, int j, string& curr, int idx) {
        if (idx == word.length()) { ans = true; return; }
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size() || 
            board[i][j] != word[idx] || board[i][j] == '*') return;

        char temp = board[i][j];
        board[i][j] = '*';
        search(board, word, i - 1, j, curr, idx + 1);
        search(board, word, i + 1, j, curr, idx + 1);
        search(board, word, i, j - 1, curr, idx + 1);
        search(board, word, i, j + 1, curr, idx + 1);
        board[i][j] = temp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() * board[0].size() < word.size()) return false;
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {
                    string curr = "";
                    search(board, word, i, j, curr, 0);
                    if (ans) return ans;
                }
            }
        }
        return false;
    }
};