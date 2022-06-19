class Solution {
    public int maxSubArray(int[] nums) {
     if (nums.length == 0){
         return 0;
     }
 
     int prev = nums[0];
     int cur = nums[0];
     int max = nums[0];
     
     for (int i = 1; i < nums.length; i++){
         if (prev > 0){
             cur = prev + nums[i];
         }else{
             cur = nums[i];
         }
         max = Math.max(max, cur);
         prev = cur; 
     }
     
     return max;
 }
 }