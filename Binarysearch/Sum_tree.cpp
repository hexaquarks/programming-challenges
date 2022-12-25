#include <functional>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster than 80% */
bool solve(Tree* root) 
{
    bool ans = true;
    function<void(Tree*)> DFS = [&](Tree* node)
    {
        if (!node || !ans) return;
        if (node->left || node->right)
        {
            if (node->left && node->right)
            {
                if (node->left->val + node->right->val != node->val) ans = false;
            }
            else if (node->left && !node->right) 
            {
                if (node->left->val != node->val) ans = false;
            }
            else if (node->right && !node->left)
            {
                if (node->right->val != node->val) ans = false;
            }
        }
        DFS(node->left);
        DFS(node->right);
    };
    DFS(root);
    return ans;
}