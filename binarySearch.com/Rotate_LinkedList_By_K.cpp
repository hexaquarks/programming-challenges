class LLNode {
    public:
        int val;
        LLNode *next;
};

/* My solution - faster than 100% */
LLNode* solve(LLNode* node, int k) 
{
    if (!node) return nullptr;
    if (!k) return node;

    LLNode* count = node;
    int counter = 0;
    while (count)
    {
        count = count->next;
        ++counter;
    }

    LLNode* head = node, *kthNode = nullptr;
    k = counter - k;
    while (node && node->next && --k) node = node->next;
    if (k) return head;

    kthNode = node->next;
    node->next = nullptr;

    LLNode* temp = kthNode;
    while (temp && temp->next) temp = temp->next;
    temp->next = head;

    return kthNode;
}

/* Circular linked list trick solution */
LLNode *solve(LLNode *node, int k) {
    LLNode *curr = node;
    int len = 1;
    while (curr->next) curr = curr->next, ++len;
    curr->next = node;
    k = len - k;
    while (k--) curr = curr->next;
    LLNode *tmp = curr->next;
    curr->next = nullptr;
    return tmp;
}
