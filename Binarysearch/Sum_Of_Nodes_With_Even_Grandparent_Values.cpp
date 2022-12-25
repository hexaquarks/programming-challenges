#include <functional>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster than 10% */
int solve(Tree* root) 
{
    int ans = 0;
    function<void(Tree*, int&)> traverse = [&](Tree* root, int& sum)
    {
        if (!root) return;

        if (root->val % 2 == 0)
        {
            if (root->left && root->left->left) sum += root->left->left->val;
            if (root->left && root->left->right) sum += root->left->right->val;
            if (root->right && root->right->right) sum += root->right->right->val;
            if (root->right && root->right->left) sum += root->right->left->val;
        }
        traverse(root->left, sum);
        traverse(root->right, sum);
    };
    traverse(root, ans);
    return ans;
}

/* Better solution */
int solve(Tree* root) {
    if (root == NULL) return 0;
    int k = 0;
    if (root->val % 2 == 0) {
        if (root->left != NULL) {
            if (root->left->left != NULL) k = k + root->left->left->val;
            if (root->left->right != NULL) k = k + root->left->right->val;
        }
        if (root->right != NULL) {
            if (root->right->left != NULL) k = k + root->right->left->val;
            if (root->right->right != NULL) k = k + root->right->right->val;
        }
        return k + solve(root->left) + solve(root->right);
    }
    return solve(root->left) + solve(root->right);
}