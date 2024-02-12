class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer,Integer>x = new HashMap<>(); 
        int n  = nums.length; 
        for(int i = 0; i < nums.length ; i++){
            x.put(nums[i] , x.getOrDefault(nums[i] , 0) +1); 
            if(x.get(nums[i]) > (n/2)  ){
                return nums[i]; 
            }
        }
        return 0 ; 
    }
}