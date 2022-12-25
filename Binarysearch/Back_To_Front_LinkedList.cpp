class LLNode {
    public:
        LLNode(int);
        int val;
        LLNode *next;
};


 /* My solution - faster than 40% */
LLNode* reverse(LLNode*& node)
{
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
LLNode* solve(LLNode* node) 
{
    LLNode* curr = node, *slow = node, *fast = node;
    LLNode* result = new LLNode(-1);
    LLNode* pResult = result;

    while (fast && fast->next)    
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    LLNode* rev = reverse(slow);
    
    int count = 0;
    while (curr != slow || rev) 
    {
        if (count % 2 == 0) 
        {
            result->next = new LLNode(rev->val);
            result = result->next;
            rev = rev->next;
        }
        else
        {
            result->next = new LLNode(curr->val);
            result = result->next;
            curr = curr->next;
        }
        ++count;
    }
    return pResult->next;
}