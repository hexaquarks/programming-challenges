/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;

        ListNode* curr = head;
        ListNode* ans = nullptr;

        int length = 1;
        // make cycle
        while (curr->next) {
            curr = curr->next;
            ++length;
        }
        curr->next = head;
        int remaining = length - k % length;
        for (int i = 0; i < remaining; ++i) curr = curr->next;

        ans = curr->next;
        curr->next = nullptr;

        return ans;
    }
};
Console
