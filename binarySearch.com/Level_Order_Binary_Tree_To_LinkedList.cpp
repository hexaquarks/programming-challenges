#include <queue>

using namespace std; 

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

/* My solution - faster tahn 90% */
LLNode* solve(Tree* root) 
{
    if (!root) return nullptr;
    LLNode* ans = new LLNode();   
    LLNode* pAns = ans;

    queue<Tree*> q;
    q.push(root);
    while(!q.empty())
    {
        Tree* curr = q.front();
        q.pop();
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
        pAns->next = new LLNode(curr->val);
        pAns = pAns->next;
    }
    return ans->next;
}