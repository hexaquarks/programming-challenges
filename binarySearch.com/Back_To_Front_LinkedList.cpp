class LLNode {
    public:
        int val;
        LLNode *next;
};


 /* My solution - faster than 40% */
LLNode* reverse(LLNode*& node)
{
    LLNode* curr = node, *temp = nullptr, *prev = nullptr;

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
    if (!node) return nullptr;
    LLNode* curr = node, *slow = node, *fast = node;
    
    int n = 0;
    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
        ++n;
    }
    if (!n) return node;

    LLNode* rev = reverse(slow);
    while (node && node->next != slow) node = node->next;
    node->next = nullptr;

    LLNode* ans = new LLNode(-1);
    LLNode* pAns = ans;

    int counter = 0;
    while (rev || curr)
    {
        if (counter % 2 == 0)
        {
            ans->next = new LLNode(rev->val);
            rev = rev->next;
        }
        else 
        {
            ans->next = new LLNode(curr->val);
            curr = curr->next;
        }
        ans = ans->next;
        ++counter;
    }
    return pAns->next;
}