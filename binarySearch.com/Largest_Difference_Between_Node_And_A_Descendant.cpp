#include <vector>
#include <limits> 
#include <functional>
#include <algorithm> 

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster than 5% (lol) */
int maxDiff(vector<int> v)
{
    int minVal = *min_element(v.begin(), v.end());
    int maxVal = *max_element(v.begin(), v.end());
    return maxVal - minVal;
} 
int solve(Tree* root) 
{
    if (!root) return 0;
    int ans = numeric_limits<int>::min();
    vector<int> v{};
    function<void(Tree*, vector<int>)> DFS = [&](Tree* node, vector<int> v)
    {
        if (!node) return;
        if (!node->left && !node->right) 
        {
            v.push_back(node->val);
            ans = max(ans, maxDiff(v));
        }
        v.push_back(node->val);
        DFS(node->left, v);
        v.push_back(node->val);
        DFS(node->right, v);
    };
    DFS(root, v);
    return ans;
}