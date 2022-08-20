#include <functional> 
#include <vector> 
#include <unordered_map> 

using namespace std;

 class Tree {
     public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster than 40% */
bool solve(Tree* a, Tree* b, int target) 
{
    function<void(Tree*, vector<int>&)> DFS = [&](Tree* node, vector<int>& v)
    {
        if (!node) return;
        v.push_back(node->val);
        DFS(node->left, v);
        DFS(node->right, v);
    };
    vector<int> first, second;
    DFS(a, first);
    DFS(b, second);
    unordered_map<int, int> mem;
    for (int i = 0; i < first.size(); ++i)
    {
        mem[first[i]] = i;
    }
    for (int i = 0; i < second.size(); ++i)
    {
        int val = second[i];
        if (mem.find(target - val) != mem.end()) return true;
    }
    return false;
}

/* Insane online solution - faster than  85% */
bool solve(Tree* a, Tree* b, int target) {
    if (a == NULL || b == NULL) return false;
    if (a->val + b->val == target) return true;
    if (a->val + b->val > target) return solve(a->left, b, target) || solve(a, b->left, target);
    return solve(a->right, b, target) || solve(a, b->right, target);
}