class LLNode {
    public:
        LLNode(int);
        int val;
        LLNode *next;
};

/* My solution - Faster than 99% */
LLNode* solve(LLNode* l0, LLNode* l1) 
{
    LLNode* res = new LLNode(-1);
    LLNode* curr = res;

    int count = 0;
    while (l0 || l1)
    {
        if (count % 2 == 0)
        {
            if (!l0) 
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else 
            {
                curr->next = l0;
                l0 = l0->next;
                ++count;
            }
        }
        else
        {
            if (!l1) 
            {
                curr->next = l0;
                l0 = l0->next;
            }
            else 
            {
                curr->next = l1;
                l1 = l1->next;
                ++count;
            }
        }
        curr = curr->next;
    }
    return res->next;
}

/* Much MUCH simpler solution */
LLNode* solve(LLNode* l0, LLNode* l1) 
{
    if (!l0) return l1;
    if (!l1) return l0;
    l0->next = solve(l1, l0->next);
    return l0;
}