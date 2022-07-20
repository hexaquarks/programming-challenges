#include <stack>

class LLNode {
    public:
        LLNode(int);
        int val;
        LLNode *next;
};

/* My solution - Faster than 45% (???) */
LLNode* solve(LLNode* node) 
{
    LLNode* res = new LLNode(-1);
    LLNode* curr = res, *slow = node, *fast = node;
    std::stack<LLNode*> mem;

    while (slow && fast && fast->next)
    {
        mem.push(slow);
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast)
    {
        curr->next = slow;
        curr = curr->next;
        slow = slow->next;
    }
    while (slow)
    {
        curr->next = new LLNode(mem.top()->val + slow->val);
        mem.pop();
        curr = curr->next;
        slow = slow->next;
    }
    return res->next;
}

/* Faster community solution - Faster than 95% */
LLNode* reverseLL(LLNode* node) {
    LLNode *curr = node, *prev = nullptr, *tmp;
    while (curr) {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}
LLNode* solve(LLNode* node) {
    LLNode *slow = node, *fast = node;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = slow->next;
    slow = reverseLL(slow);
    LLNode* head = node;
    while (head && slow) {
        head->val += slow->val;
        slow = slow->next;
        head = head->next;
    }
    return reverseLL(node)->next;
}