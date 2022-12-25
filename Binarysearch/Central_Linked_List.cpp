class LLNode {
    public:
        int val;
        LLNode *next;
};

/* My solution - Faster than 100 % */
int solve(LLNode* node) 
{
    LLNode* slow = node, *fast = node;

    while (slow && fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }   
    return slow->val;
}