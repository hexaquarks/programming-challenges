class LLNode {
    public:
        int val;
        LLNode *next;
};


 /* My solution - faster than 30% */
LLNode* solve(LLNode* node) 
{
    if (!node) return nullptr;
    
    vector<int> mem;
    while (node) 
    {
        mem.push_back(node->val);
        node = node->next;
    } 
    std::sort(mem.begin(), mem.end());
    LLNode* ans = new LLNode(-1);
    LLNode* curr = ans;

    for (const int& value : mem)
    {
        ans->next = new LLNode(value);
        ans = ans->next;
    }
    return curr->next;
}

/* Merge sort solution - Much much faster */
LLNode* merge(LLNode* left, LLNode* right) {
    LLNode dummy_head;
    LLNode* curr = &dummy_head;

    while (left && right) {
        if (left->val < right->val) {
            curr->next = left;
            left = left->next;

            curr = curr->next;
            curr->next = nullptr;
        } else {
            curr->next = right;
            right = right->next;

            curr = curr->next;
            curr->next = nullptr;
        }
    }

    while (left) {
        curr->next = left;
        left = left->next;

        curr = curr->next;
        curr->next = nullptr;
    }

    while (right) {
        curr->next = right;
        right = right->next;

        curr = curr->next;
        curr->next = nullptr;
    }

    return dummy_head.next;
}

LLNode* merge_sort(LLNode* node) {
    if (!node || !node->next) return node;

    LLNode *slow = node, *fast = node, *prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = nullptr;
    LLNode* left = merge_sort(node);
    LLNode* right = merge_sort(slow);

    return merge(left, right);
}

LLNode* solve(
    LLNode* node) {  // Merge sort takes O(N logN) time and O(log N) for recursive call stack
    return merge_sort(node);
}