class LLNode {
    public:
        int val;
        LLNode *next;
};

LLNode* solve(LLNode* node, int target) 
{
    if (!node) return node;
    
    while (node && node->val == target) node = node->next;

    LLNode* curr = node; 
    LLNode* prev = nullptr;
  
    while (curr) 
    {
        if (curr->val == target) prev->next = curr->next;
        else prev = curr;

        curr = curr->next;
    }

    return node;
}