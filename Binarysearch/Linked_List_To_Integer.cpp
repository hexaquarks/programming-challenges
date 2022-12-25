#include <math.h>

using namespace std;

class LLNode {
    public:
        int val;
        LLNode *next;
};

int solve(LLNode* node) 
{
    LLNode* temp = node;
    int size = 0, ans = 0;
    while (temp)
    {
        ++size;
        temp = temp->next;
    }
    while (node && size--)
    {
        if (node->val == 1) 
        {
            ans += pow(2, size);
        }
        node = node->next;
    }
    return ans;
}