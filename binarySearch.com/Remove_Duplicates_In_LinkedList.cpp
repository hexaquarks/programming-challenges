class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster 85% */
LLNode* solve(LLNode* node) 
{
    if (!node) return nullptr;

    LLNode* curr = node;
    unordered_set<int> mem;

    mem.insert(node->val);
    while (node && node->next)
    {
        mem.insert(node->val);
        while (node && node->next && mem.find(node->next->val) != mem.end())
        {
            node->next = node->next->next;
        }
        if (!node->next) break;
        else node = node->next;    
    }
    return curr;
}