/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        
        traverseTree(root, result);
        return result;
        
    }
    
    public void traverseTree(TreeNode node, ArrayList<Integer> result) {
        if(node == null) return;
        
        traverseTree(node.left, result);
        traverseTree(node.right, result);
        
        result.add(node.val);
        
    }
}