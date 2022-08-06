class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

#include <numeric>

/* Cool online solution - faster than 90% */
int solve(Tree* root) 
{
    int leftMost = std::numeric_limits<int>::max();
    int rightMost = std::numeric_limits<int>::min();

    function<void(Tree*, int)> DFS = [&](Tree* node,int pos) 
    {
        if (!node) return;
        leftMost = min(leftMost, pos);
        rightMost = max(rightMost, pos);
        DFS(node->left, pos - 1);
        DFS(node->right, pos + 1);
    };
    DFS(root, 0);
    return rightMost - leftMost + 1;
}
