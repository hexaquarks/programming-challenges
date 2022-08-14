class LLNode {
    public:
        int val;
        LLNode *next;
};

/* My solution - Faster than 99% */
{
    if (!node) return nullptr;

    LLNode* res = node;

    while (node && node->next)
    {
        int temp = node->val;
        node->val = node->next->val;
        node->next->val = temp;

        node = node->next->next;
    }

    return res;
}