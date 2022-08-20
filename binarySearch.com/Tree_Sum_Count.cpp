#include <functional>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* Online solution - faster than 60 %*/
int solve(Tree* root, int k) 
{
    if (!root) return 0;
    unordered_map<int, int> mem;
    int ans = 0;

    function<void(Tree* ,int)> DFS = [&](Tree* node, int sum)
    {
        sum += node->val;
        ans += mem[sum - k];

        ++mem[sum];
        if (node->left) DFS(node->left, sum);
        if (node->right) DFS(node->right, sum);
        --mem[sum];
    };
    mem[0] = 1;
    DFS(root, 0);
    return ans;
}

/* Much cooler solution - faster than 80% */
int solve(Tree* root, int k) {
    int ans = 0;
    function<void(Tree*, int, bool)> dfs = [&](Tree* root, int val, bool head) {
        if (!root) return;
        if (root->val + val == k) ans++;
        dfs(root->left, val + root->val, false);
        dfs(root->right, val + root->val, false);
        if (head) {
            dfs(root->left, 0, true);
            dfs(root->right, 0, true);
        }
    };
    dfs(root, 0, true);
    return ans;
}
