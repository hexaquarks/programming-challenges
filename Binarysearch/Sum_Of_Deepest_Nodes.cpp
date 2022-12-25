#include <functional>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* Standard solution - faster than 50% */
int solve(Tree* root) 
{
    int depth = 0, ans = 0;
    if (!root) return 0;
    function<int(Tree*, int)> DFS = [&](Tree* node, int level)
    {
        if (!node) return 0;
        if (!node->left && !node->right)
        {
            if (level > depth)
            {
                ans = node->val;
                depth = level;
            }
            else if (level == depth) ans += node->val;
        }
        DFS(node->left, level + 1);
        DFS(node->right, level + 1);
        return ans;
    };
    return DFS(root, depth);
}