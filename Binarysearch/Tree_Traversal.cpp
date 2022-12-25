#include <string>
#include <stack>
#include <vector>

using namespace std; 

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* My solution - faster than 80% */
int solve(Tree* root, vector<string>& moves) 
{
    int counter = 0;
    stack<Tree*> st;
    for (const string& s : moves)
    {
        if (moves[counter] == "UP") { 
            root = st.top();
            st.pop();
        }
        else if (moves[counter] == "RIGHT") { 
            st.push(root);
            root = root->right;
        }
        else if (moves[counter] == "LEFT") { 
            st.push(root);
            root = root->left;
        }
        ++counter;
    }
    return root->val;
}