#include <functional>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster than 0.5% lol (obviously) */
Tree* solve(Tree* root) 
{
    function<bool(Tree*&)> DFS = [&](Tree*& node)
    {
        if (!node) return false;
        if (node->val % 2 == 0 && !node->left && !node->right) { node = nullptr; return true; }
        return DFS(node->left) || DFS(node->right);
    };
    while (DFS(root)) 
    { 
        if (!root) return nullptr; 
    }
    return root;
}

/* Much better solution - faster than 80%*/
Tree* solve(Tree* root) {
    if (!root) return root;
    root->left = solve(root->left);
    root->right = solve(root->right);
    if (!root->left && !root->right && root->val % 2 == 0) return NULL;
    return root;
}