
using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster than 25% */
Tree* solve(Tree* node0, Tree* node1) 
{
    if (!node0 && !node1) return nullptr;
    else if (!node0 && node1) return node1;
    else if (node0 && !node1) return node0;

    node0->val += node1->val;
    node0->left = solve(node0->left, node1->left);
    node0->right = solve(node0->right, node1->right);
    return node0;
}

/* Cleaner solution */
Tree* solve(Tree* node0, Tree* node1) {
    if (node0 && node1) {
        node0->val += node1->val;
        node0->left = solve(node0->left, node1->left);
        node0->right = solve(node0->right, node1->right);
    }
    return node0 ? node0 : node1;
}