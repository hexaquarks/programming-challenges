#include <numeric>

using namespace std;

class LLNode {
    public:
        int val;
        LLNode *next;
};

bool solve(LLNode* head) 
{
    int minVal = numeric_limits<int>::min();

    while (head)
    {
        if (head->val > minVal) minVal = head->val;
        else return false;
        head = head->next;
    }    
    return true;
}