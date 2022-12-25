class LLNode {
    public:
        int val;
        LLNode *next;
};

int solve(LLNode* node) 
{
    int n = 0;
    while (node)
    {
        ++n;
        node = node->next;
    }
    return n;
}