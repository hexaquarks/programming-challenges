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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = new ListNode(0);
        ListNode* ans = temp;
        ListNode* curr = head;

        curr = curr->next;
        int sum = 0;
        while (curr)
        {
            if (curr->val == 0)
            {
                temp->next = new ListNode(sum);
                temp = temp->next;
                sum = 0;
            } 
            else { sum += curr->val; }
            curr = curr->next;
        }
        return ans->next;
    }
};