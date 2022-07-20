class LLNode {
    public:
        LLNode(int);
        int val;
        LLNode *next;
};

/* My solution - Faster than 96% */
LLNode* solve(LLNode* node, int k) 
{
    LLNode* res = new LLNode(-1);
    LLNode* curr = res;
    LLNode* lessE = new LLNode(-1), *moreE = new LLNode(-1), *equalE = new LLNode(-1);
    LLNode* less = lessE, *more = moreE, *equal = equalE;

    while (node)
    {
        if (node->val < k) { less->next = new LLNode(node->val); less = less->next; }
        else if (node->val > k) { more->next = new LLNode(node->val); more = more->next; }
        else { equal->next = new LLNode(node->val); equal = equal->next; }
        
        node = node->next;
    }

    less->next = equalE->next;
    equal->next = moreE->next;
    return lessE->next;
}