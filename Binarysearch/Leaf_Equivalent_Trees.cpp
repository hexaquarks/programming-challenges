#include <vector>
#include <functional>
#include <stack>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution (the obvious one) - Faster than 15% */
bool solve(Tree* root0, Tree* root1) 
{
    vector<int> l, r;
    function<void(Tree*, vector<int>&)> DFS = [&](Tree* node, vector<int>& v)
    {
        if (!node) return;
        if (!node->left && !node->right) v.push_back(node->val);
        DFS(node->left, v);
        DFS(node->right, v);
    };
    DFS(root0, l);
    DFS(root1, r);

    return l == r;
}

/* Accepted harder solution */
class TreeIterator {
    private:
    stack<Tree*> s;
    void Add(Tree* root) {
        if (root) {
            s.emplace(root);
        }
    }

    public:
    TreeIterator(Tree* root) {
        Add(root);
    }

    bool HasNext() {
        return !s.empty();
    }

    Tree* GetLeaf() {
        while (HasNext()) {
            Tree* curr = s.top();
            s.pop();

            if (curr->left == nullptr && curr->right == nullptr) {
                return curr;
            } else {
                Add(curr->right);
                Add(curr->left);
            }
        }
        return nullptr;
    }
};

bool solve(Tree* root0, Tree* root1) {
    TreeIterator it0(root0), it1(root1);

    while (it0.HasNext() && it1.HasNext()) {
        Tree* leaf0 = it0.GetLeaf();
        Tree* leaf1 = it1.GetLeaf();

        if (leaf0->val != leaf1->val) {
            return false;
        }
    }

    return !it0.HasNext() && !it1.HasNext();
}