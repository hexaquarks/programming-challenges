class LLNode {
public:
    LLNode(int val_, LLNode* next_) { val = val_; next = next_; }
    int val;
    LLNode *next;
};

LLNode* solve(LLNode* head, int pos, int val) 
{
    LLNode* dummy = new LLNode(-1, head);
    LLNode* prev = dummy;
    
    while (pos--) // executes body until pos == -1. So it includes pos == 0, as opposed to --pos prefix.
    {
        prev = head;
        head = head->next;
    }
    LLNode* temp = new LLNode(val, head);
    prev->next = temp;
    return dummy->next;
}
// My solution 

// LLNode* solve(LLNode* head, int pos, int val) 
// {
//     LLNode* newNode = new LLNode();
//     newNode->val = val;

//     if (!head) 
//     {   
//         newNode->next = nullptr;
//         head = newNode;
//         return head;
//     }

//     LLNode* temp = head;
//     int i = 0;

//     if (pos == 0) 
//     {
//         newNode->next = head;
//         return newNode;
//     }

//     while (temp)
//     {
//         if (i == pos - 1) 
//         {
//             newNode->next = temp->next;
//             temp->next = newNode;

//             return head;
//         }
//         temp = temp->next;    
//         ++i;
//     }
//     return nullptr;
// }