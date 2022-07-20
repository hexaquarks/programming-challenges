#include <algorithm>

class LLNode {
    public:
        int val;
        LLNode *next;
};
/* My solution - Faster than 90% */
LLNode* solve(LLNode* node, int k) 
{
    if (!node) return nullptr;
    LLNode* slow = node, *fast = node, *kth = nullptr;

    while (k--)
    {
        fast = fast->next;
    }
    kth = fast;
    while (fast && fast->next) 
    {
        fast = fast->next;
        slow = slow->next;
    }
    std::swap(kth->val, slow->val);
    return node;
}

// 1 - 2 - 3 - 4 - 5 - 6 , k = 2
//                         f   
//     k
//                 s