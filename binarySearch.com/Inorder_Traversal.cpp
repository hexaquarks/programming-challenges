#include <functional>
#include <vector>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster than 100% */
void DFS(Tree* node, vector<int>& ans)
{
    if (!node) return;
    DFS(node->left, ans);
    ans.push_back(node->val);
    DFS(node->right, ans);
}
vector<int> solve(Tree* root) 
{
    vector<int> ans;
    DFS(root, ans);
    return ans;
}