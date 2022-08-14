#include <functional>
#include <queue>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster than 20% */
int solve(Tree* root) 
{
    if (!root) return 0;
    int height = -1;
    function<void(Tree*, int)> FindHeight = [&](Tree* node, int level)
    {
        if (!node) return;
        if (level > height) height = level;
        FindHeight(node->left, level + 1);
        FindHeight(node->right, level + 1);
    };

    FindHeight(root, 0);
    pair<Tree*, Tree*> ans{nullptr, nullptr};

    function<void(Tree*, int)> DFS = [&](Tree* node, int level)
    {
        if (!node) return;
        if (level == height)
        {
            if (!ans.first) ans.first = node;
            else ans.second = node;
            return;
        }
        DFS(node->left, level + 1);
        DFS(node->right, level + 1);
    };
    DFS(root, 0);
    if (ans.first && ans.second) return ans.first->val;
    else if (ans.first) return ans.first->val;
    else if (ans.second) return ans.second->val;
    return 0;
}

/* Much much better answer for obvious reasons */
int solve(Tree* root) {
    queue<Tree*> q;
    q.push(root);
    while (!q.empty()) {
        root = q.front();
        q.pop();
        if (root->right) q.push(root->right);
        if (root->left) q.push(root->left);
    }
    return root->val;
}