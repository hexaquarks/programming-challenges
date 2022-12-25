#include <functional>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* Online solution - faster than 20% */
bool solve(Tree* root, Tree* target) 
{
    if (!target) return false;
    function<bool(Tree*, Tree*)> areIdentical = [&](Tree* node, Tree* target)
    {
        if (!node && !target) return true;
        if (!node || !target) return false;

        return (node->val == target->val && 
            areIdentical(node->left, target->left) && areIdentical(node->right, target->right));
    };
    
    function<bool(Tree*)> DFS = [&](Tree* node)
    {
        if (!target) return true;
        if (!node) return false;
        if (areIdentical(node, target)) return true;
        return DFS(node->left) || DFS(node->right);
    };
    return DFS(root);
}