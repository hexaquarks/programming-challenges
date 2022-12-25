class LLNode {
    public:
        int val;
        LLNode *next;
};

LLNode* solve(LLNode* node) 
{
    LLNode* temp = node;

    while (node && node->next)
    {
        int val = node->val;
        while (--val && node->next)
        {
            node->next = node->next->next;
        }
        node = node->next;
    }
    return temp;
}

// Note that if val = 2, then 
// while (--val) 	prints 1
// while (val) {--val}  prints 2, 1
// while (val--) 	prints 1, 0
