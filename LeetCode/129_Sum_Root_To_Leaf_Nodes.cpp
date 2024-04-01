
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
int total = 0;
public:
    void dfs(TreeNode* node, string& curr) {
        if (node == nullptr) {
            return;
        }

        curr += node->val  + '0';
        if (!node->left && !node->right) {
            total += stoi(curr);
        } else {
            dfs(node->left, curr);
            dfs(node->right, curr);
        }
        curr.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        string curr = "";
        dfs(root, curr);
        return total;
    }
};