class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - Faster than 61% */
bool solve(LLNode* node) 
{
    if (!node) return true;
    LLNode* fast = node, *slow = node;
    stack<int> mem;

    while (slow && fast && fast->next)
    {
        mem.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }
    if (!fast)
    {
        if (slow->val != mem.top()) return false;
        mem.pop();
    }
    slow = slow->next;
    while (slow)
    {
        if (slow->val != mem.top()) return false;
        mem.pop();
        slow = slow->next;
    }
    return true;
}

/* More neat solution - Faster than 70% */
/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
bool checkPalindrome(LLNode *node, LLNode **curr) {
    if (node == NULL) return true;
    bool check = checkPalindrome(node->next, curr);
    if (node->val != (*curr)->val) return false;
    *curr = (*curr)->next;
    return check;
}
bool solve(LLNode *node) {
    LLNode *curr = node;
    return checkPalindrome(node, &curr);
}