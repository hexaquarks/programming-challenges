class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};


class LLNode {
    public:
        int val;
        LLNode *next;
};

/* My solution - Faster than 100% */
Tree* solve(LLNode* node) 
{
    if (!node) return nullptr;

    Tree* res = new Tree(node->val);
    Tree* curr = res;
    node = node->next;

    while (node)
    {
        if (node->val >= curr->val)
        {
            curr->right = new Tree(node->val);
            curr = curr->right;
        }
        else 
        {
            curr->left = new Tree(node->val);
            curr = curr->left;
        }
        node = node->next;
    }
    return res;
}