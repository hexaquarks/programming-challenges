#include <functional>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster than 25% */
Tree* solve(Tree* root) 
{
    if (!root) return nullptr;
    function<void(Tree*)> DFS = [&](Tree* node)
    {
        if (!node) return;
        DFS(node->left);
        DFS(node->right);
        if (node && (node->left || node->right))
        {
            swap(node->left, node->right);
            return;
        }
    };
    DFS(root);
    return root;
}