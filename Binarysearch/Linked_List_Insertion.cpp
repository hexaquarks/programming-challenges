
class LLNode {
    public:
        LLNode(int);
        int val;
        LLNode *next;
};

/* My solution - Faster than 47% */
LLNode* solve(LLNode* l0, LLNode* l1) 
{
    LLNode result(0);
    LLNode* curr = &result;

    while (l0 && l1)
    {
        if (l0->val == l1->val)
        {
            curr->next = new LLNode(l0->val);
            l0 = l0->next;
            l1 = l1->next;
            curr = curr->next;
        }
        else if (l0->val > l1->val) l1 = l1->next;
        else if (l1->val > l0->val) l0 = l0->next;
    }
    return result.next;
}