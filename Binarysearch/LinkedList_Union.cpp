#include <unordered_set>

class LLNode {
    public:
        int val;
        LLNode *next;
};

/* My solution - Faster than 25% */
LLNode* solve(LLNode* ll0, LLNode* ll1) 
{
    // edge cases
    if (!ll0 && !ll1) return nullptr;
    if (!ll0) return ll1;
    if (!ll1) return ll0;

    LLNode* result = new LLNode(-1);
    LLNode* pResult = result;
    unordered_set<int> mem;

    int count = ll0->val < ll1->val ? 0 : 1;
    while (ll0 || ll1)
    {
        if (count % 2 == 0)
        {
            if (mem.find(ll0->val) == mem.end())
            {
                mem.insert(ll0->val);
                result->next = new LLNode(ll0->val);
                result = result->next;
            }
            ll0 = ll0->next;
            if (!ll0 || (ll1 && ll0->val >= ll1->val)) ++count;
        }
        else
        {
            if (mem.find(ll1->val) == mem.end())
            {
                mem.insert(ll1->val);
                result->next = new LLNode(ll1->val);
                result = result->next;
            }
            ll1 = ll1->next;
            if (!ll1 || (ll0 && ll1->val >= ll0->val)) ++count;
        }
    }    
    return pResult->next;
}

/* Faster and neatter accepted solution */
LLNode* solve(LLNode* ll0, LLNode* ll1) {
    if (ll0 == NULL) return ll1;
    if (ll1 == NULL) return ll0;

    LLNode* c;
    if (ll0->val > ll1->val) {
        c = ll1;
        ll1->next = solve(ll0, ll1->next);
    } else if (ll0->val < ll1->val) {
        c = ll0;
        ll0->next = solve(ll0->next, ll1);
    } else {
        c = ll0;
        ll0->next = solve(ll0->next, ll1->next);
    }

    return c;
}