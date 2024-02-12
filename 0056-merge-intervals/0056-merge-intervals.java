class Solution {
    public int[][] merge(int[][] a) {
        Arrays.sort(a , (p , q)->Integer.compare(p[0] , q[0])); 
        List<int[]>ans = new ArrayList<>(); 
        int n = a.length ; 
        int mn = Integer.MAX_VALUE ; 
        int mx = Integer.MIN_VALUE ;
        for(int[]b : a){
            if(b[0] > mx){
                if(mx != Integer.MIN_VALUE){
                    ans.add(new int[]{mn , mx}); 
                }
                mn = b[0] ;
                mx = b[1] ;
            }else{
                mn = Math.min(mn , b[0]); 
                mx = Math.max(mx , b[1]); 
            }
        }
        ans.add(new int[]{mn , mx }); 
        return ans.toArray(new int[ans.size()][]); 
    }
}