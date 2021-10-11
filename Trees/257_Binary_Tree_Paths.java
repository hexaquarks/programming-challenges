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
    public List<String> binaryTreePaths(TreeNode root) {
        ArrayList<String> result = new ArrayList<String>();
        traverse(root, "", result);
        return result;
        
    }
    
    public void traverse(TreeNode node, String path, ArrayList<String> result){
        if(node == null) return;
        
        // at the leaf
        if(node.left == null && node.right == null) {
            result.add(path + node.val);
            return;
        }
        
        if(node.left != null) traverse(node.left, path+node.val+"->", result);
        if(node.right != null) traverse(node.right, path+node.val+"->", result);
        
    }
}