
class LLNode {
    public:
        int val;
        LLNode *next;
};

/* My solution - Faster than 95% (learned from LeetCode) */
LLNode* solve(LLNode* l1, LLNode* l2) {
    LLNode result(-1);
    LLNode* curr = &result;
    int sum = 0;

    while (l1 || l2)
    {
        if (l1) { sum += l1->val; l1 = l1->next; }
        if (l2) { sum += l2->val; l2 = l2->next; }

        curr->next = new LLNode(sum % 10);
        sum /= 10;
        curr = curr->next;
    }
    if (sum > 0)
    {
        curr->next = new LLNode(sum);
    }
    return result.next;
}