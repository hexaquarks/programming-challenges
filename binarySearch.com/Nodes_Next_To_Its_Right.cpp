#include <queue>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

Tree* solve(Tree* tree, int target) 
{
    if (!tree) return 0;
  
    queue<Tree* > q; 
    queue<int> qLevel; 
  
    int level = 0; 
  
    q.push(tree);
    qLevel.push(level);
  
    while (q.size())
    {
        Tree* node = q.front();
        level = qLevel.front();
        q.pop();
        qLevel.pop();
  
        if (node->val == target)
        {
            if (qLevel.size() == 0 || qLevel.front() != level) return nullptr;
            return q.front();
        }
  
        if (node->left)
        {
            q.push(node->left);
            qLevel.push(level+1);
        }
        if (node->right)
        {
            q.push(node->right);
            qLevel.push(level+1);
        }
    }
    return nullptr;    
}