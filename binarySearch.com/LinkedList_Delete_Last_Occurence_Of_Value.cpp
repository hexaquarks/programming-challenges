#include <limits>

class LLNode {
    public:
        int val;
        LLNode *next;
};

/* My solution - Faster than 88% */
LLNode* solve(LLNode* node, int target) 
{
    int idx = std::numeric_limits<int>::min();
    int count = 0;
    LLNode* curr = node;

    while (curr)
    {
        if (curr->val == target) idx = count;
        ++count;
        curr = curr->next;
    }
    if (count == 1)
    {
        if (idx != std::numeric_limits<int>::min()) return nullptr;
        else return node;
    }
    if (idx == 0) { node = node->next; return node; }
    
    curr = node;
    count = 0;
    while (curr)
    {
        if (count == idx - 1) { curr->next = curr->next->next; break; }
        ++count;
        curr = curr->next;
    }
    return node;
}

/* Much cleaner solution */
LLNode* solve(LLNode* node, int target) 
{
    LLNode* curr = node, *temp = nullptr;

    while (curr->next)
    {
        if (curr->next->val == target) temp = curr;
        curr = curr->next;
    }
    if (!temp) 
    {
        return  (node->val == target) ? node->next : node;
    }
    curr = temp;
    curr->next = curr->next->next;
    return node;
}