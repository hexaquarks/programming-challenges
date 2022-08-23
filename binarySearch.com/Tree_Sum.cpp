class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};
/* My solution - faster than 10% */ 
void DFS(Tree* node, vector<int>& v)
{
    if (!node) return;
    v.push_back(node->val);
    DFS(node->left, v);
    DFS(node->right, v);
}
int solve(Tree* root) 
{
    vector<int> v;
    DFS(root, v);
    int ans = std::accumulate(v.begin(), v.end(), 0);
    return ans;
}

/* Cool solution */
int solve(Tree* root) {
    if (root == NULL) return 0;
    return root->val + solve(root->left) + solve(root->right);
}