#include <stack>

using namespace std;

 class LLNode {
     public:
         int val;
         LLNode *next;
 };
 

/*  Naive O(n^2) solution */
LLNode* solve(LLNode* node) 
{
    if (!node) return nullptr;
    LLNode* temp = node;
    int maxVal = 0;

    while (node && node->next)
    {
        LLNode* curr = node->next;
        int val = node->val;
        int currVal = curr->val;

        while (curr && curr->next)
        {
            if (currVal > val) break;
            curr = curr->next;
            currVal = curr->val;
        }
        if (currVal > node->val) node->val = curr->val;
        else node->val = 0;
        node = node->next;
    }
    if (!node->next)
    {
        node->val = 0;
    }
    return temp;
}

/* Much better solution - LIFO stack */
LLNode* solve(LLNode* node) {
    stack<LLNode*> s;
    LLNode* head = node;

    while (node != nullptr) 
    {
        while (!s.empty() && s.top()->val < node->val) 
        {
            s.top()->val = node->val;
            s.pop();
        }
        s.push(node);
        node = node->next;
    }
    while (!s.empty()) 
    {
        s.top()->val = 0;
        s.pop();
    }
    return head;
}