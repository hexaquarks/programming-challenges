class Tree {
    public:
        int val;
        Tree *left;
 Tree *right;
};

/* My solution - faster than ~80% */
bool solve(Tree* root, int target) 
{
    if (!root) return false;
    if (root->val == target) return true;
    else return solve(root->right, target) || solve(root->left, target) ;
}
