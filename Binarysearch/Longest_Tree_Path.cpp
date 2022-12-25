#include <algorithm>

using namespace std;

class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;
};

/* Online solution from Geeks4Geeks */
int diameter(Tree* node, int& height)
{
    if (!node) return 0; 

    int lh = 0, rh = 0;
    int ldiameter = 0, rdiameter = 0;
  
    if (!node) {
        height = 0;
        return 0; 
    }
  
    ldiameter = diameter(node->left, lh);
    rdiameter = diameter(node->right, rh);
  
    height = max(lh, rh) + 1;
  
    return max(lh + rh + 1 , max(ldiameter, rdiameter));
}
int solve(Tree* root) 
{
    int height = 0;
    return diameter(root, height);
}

/* Accepted solution on Binarysearch */
int Diameter(Tree* root, int& diameter) {
    if (root == nullptr) {
        return 0;
    }

    // Get the heights of the sub-trees
    int leftHeight = Diameter(root->left, diameter);
    int rightHeight = Diameter(root->right, diameter);

    // Update the diameter
    diameter = max(diameter, 1 + leftHeight + rightHeight);

    // Return the height of the tree rooted
    // at this node
    return 1 + max(leftHeight, rightHeight);
}
int solve(Tree* root) {
    int diameter = 0;
    Diameter(root, diameter);
    return diameter;
}
