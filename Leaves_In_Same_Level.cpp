using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster than 80% */
void DFS(Tree* node, bool& firstLeaf, bool& terminate, int& val, int currLevel)
{
    if (!node || terminate) return;
    if (!node->left && !node->right)
    {
        if (!firstLeaf)
        {
            firstLeaf = true;
            val = currLevel;
        }
        else
        {
            if (currLevel != val) terminate = true;
        }
        return;
    }
    DFS(node->left, firstLeaf, terminate, val, currLevel + 1);
    DFS(node->right, firstLeaf, terminate, val, currLevel + 1);
}
bool solve(Tree* root) 
{
    if (!root) return true;
    bool firstLeaf = false;
    bool terminate = false;
    int val = -1;
    DFS(root, firstLeaf, terminate, val, 0);
    return !terminate;
}