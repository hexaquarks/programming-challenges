#include <limits>
#include <functional>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster than 20% */
int solve(Tree* root, int t) 
{
    int succ = numeric_limits<int>::max();
    function<void(Tree* node)> DFS = [&](Tree* node)
    {
        if (!node) return;
        if (node->val > t) succ = min(succ, node->val);
        DFS(node->left);
        DFS(node->right);
    };
    DFS(root);
    return succ;
}

/* Accepted better solution - faster than 80% */
int solve(Tree* root, int t) {
    int ans = numeric_limits<int>::max();
    while (root != NULL) {
        if (root->val > t) {
            ans = min(ans, root->val);
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ans;
}