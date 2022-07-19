class LLNode {
    public:
        int val;
        LLNode *next;
};

/* My solution - Faster than 100% */
int solve(LLNode* node, int k) 
{
    LLNode* slow = node, *fast = node;

    while (k--)
    {
        slow = slow->next;
    }
    
    while (slow && fast && slow->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    return fast->val;
}