#include <functional>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster than 90% */
int solve(Tree* root, int lo, int hi) 
{
    int counter = 0;
    function<void(Tree*)> DFS = [&](Tree* node)
    {
        if (!node) return;
        if (node->val >= lo && node->val <= hi) ++counter;
        DFS(node->left);
        DFS(node->right);
    };
    DFS(root);
    return counter;
}