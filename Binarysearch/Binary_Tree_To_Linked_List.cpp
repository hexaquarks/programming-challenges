
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
LLNode* solve(Tree* root) 
{
    if (!root) return nullptr;
    LLNode* listL = (root->left) ? solve(root->left) : nullptr;
    LLNode* listR = (root->right) ? solve(root->right) : nullptr;
    LLNode* listM = new LLNode(root->val);

    listM->next = listR;
    if (!listL) return listM; 
    LLNode* last = listL;
    while (last->next) last=last->next; 
    last->next = listM; 
    return listL;
}

/* Alternative nice solution */
void dfs(Tree* root, LLNode*& res) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL) {
        dfs(root->left, res);
    }
    res->next = new LLNode(root->val);
    res = res->next;
    if (root->right != NULL) {
        dfs(root->right, res);
    }
}
LLNode* solve(Tree* root) {
    LLNode* res = new LLNode(-1);
    LLNode* ans = res;
    dfs(root, res);
    ans = ans->next;
    return ans;
}
