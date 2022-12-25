
class LLNode {
    public:
        int val;
        LLNode *next;
};

/* My solution - faster than 85% */
LLNode* solve(LLNode* node, int k) 
{
    if (!node) return nullptr;
    if (!k) return node;

    LLNode* curr = node, *prev = nullptr, *temp = nullptr;

    int count = 0;
    while (curr && count < k)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        ++count;
    }

    if (node) node->next = solve(temp, k);
    return prev;
}
