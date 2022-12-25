
class LLNode {
    public:
        int val;
        LLNode *next;
};

/* Normal solution */
LLNode* solve(LLNode* node) 
{
    if (!node) return nullptr;
    LLNode* curr = node, *prev = nullptr, *temp = nullptr;

    while (curr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

/* Using reccursion */
LLNode* solve(LLNode* node) {
    if (!node || !node->next) return node;

    LLNode* curr = solve(node->next);

    node->next->next = node;
    node->next = nullptr;

    return curr;
}