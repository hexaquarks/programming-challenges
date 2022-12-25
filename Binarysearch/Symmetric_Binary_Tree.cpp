#include <functional>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* Standard solution - faster than 100% */
bool solve(Tree* root) 
{
    function<bool(Tree*, Tree*)> isMirror = [&](Tree* node1, Tree* node2)
    {
        if (!node1 && !node2) return true;
        if (node1 && node2 && node1->val == node2->val) 
        {
            return isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left);
        }
        return false;
    };
    return isMirror(root, root);
}