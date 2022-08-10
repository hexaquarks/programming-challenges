#include <functional>
#include <stack>

using namespace std; 

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};


/* My solution - faster than 20% */
bool solve(Tree* root) 
{
    vector<int> v;
    function<void(Tree*)> DFS = [&](Tree* node)
    {
        if (!node) return;
        DFS(node->left);
        v.push_back(node->val);
        DFS(node->right);
    };
    DFS(root);
    int i = 0, j = v.size() - 1;
    while (i <= j)
    {
        if (v[i] != v[j]) return false;
        ++i; --j;
    }
    return true;
}

/* Accepted oline solution - faster tha 90% */
void sol1(Tree* root, stack<Tree*>& s) {
    while (root) {
        s.push(root);
        root = root->left;
    }
}
void sol2(Tree* root, stack<Tree*>& s) {
    while (root) {
        s.push(root);
        root = root->right;
    }
}
bool solve(Tree* root) {
    stack<Tree*> s1, s2;
    sol1(root, s1);
    sol2(root, s2);
    while (!s1.empty() && (!s2.empty())) {
        auto x = s1.top();
        // cout<<x->val<<" ";
        auto y = s2.top();
        cout << y->val << " ";
        s1.pop();
        s2.pop();
        if (x->val != y->val) return false;
        sol1(x->right, s1);
        sol2(y->left, s2);
    }
    return true;
}