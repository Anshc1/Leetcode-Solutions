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
    int mx = 0 ; 
    Map<Integer,Integer>ct =new HashMap<Integer,Integer>() ;
    public int dfs(TreeNode u){
        if(u == null){
            return 0 ; 
        }
        int val = u.val; 
        val += dfs(u.left); 
        val += dfs(u.right);
        ct.put(val , ct.getOrDefault(val , 0 ) + 1); 
        mx = Math.max(mx, ct.get(val)); 
        return val ; 
    }
    public int[] findFrequentTreeSum(TreeNode root) {
        dfs(root); 
        List<Integer>ans = new ArrayList<>(); 
        for(Map.Entry<Integer, Integer> i : ct.entrySet()){
            if(i.getValue() == mx){
                ans.add(i.getKey()); 
            }
        }
        int []res = new int[ans.size()]; 
        for(int i = 0; i < ans.size() ; i++){
            res[i] = ans.get(i) ; 
        }
        return res; 
    }
}