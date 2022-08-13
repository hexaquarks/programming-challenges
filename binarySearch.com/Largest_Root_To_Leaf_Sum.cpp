#include <functional>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster than 100% */
int solve(Tree* root) 
{
    if (!root) return 0;
    int maxSum = -1;
    function<void(Tree*, int)> DFS = [&](Tree* node, int sum)
    {
        if (!node) return;
        DFS(node->left, sum + node->val);
        DFS(node->right, sum + node->val);
        maxSum = max(maxSum, sum + node->val);
    };
    DFS(root, 0);
    return maxSum;
}
