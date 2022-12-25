
class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster than 80% */
void DFS(Tree* node, int level, int& maxLevel, vector<int>& v)
{
    if (!node) return;
    if (level > maxLevel) 
    {
        v.push_back(node->val);
        maxLevel = level;
    }
    DFS(node->left, level + 1, maxLevel , v);
    DFS(node->right, level + 1, maxLevel , v);
}
vector<int> solve(Tree* root) 
{
    int maxLevel = 0;
    vector<int> ans;
    DFS(root, 1, maxLevel, ans);
    return ans;
}
