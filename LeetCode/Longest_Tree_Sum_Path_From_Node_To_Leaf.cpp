#include <functional>

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
    int maxVal = -1;
    int maxLevel = -1;

    function<void(Tree*, int, int)> DFS = 
    [&](Tree* node, int level, int sum)
    {
        if (!node) return;
        if (!node->left && !node->right)
        {
            if (level > maxLevel) 
            {
                maxLevel = level;
                maxVal = sum + node->val;
            }
            else if (level == maxLevel)
            {
                maxVal = max(maxVal, sum + node->val);
            }
            return;
        }
        DFS(node->left, level + 1, sum + node->val);
        DFS(node->right, level + 1, sum + node->val);
    };
    DFS(root, 0, 0);
    return maxVal;
}