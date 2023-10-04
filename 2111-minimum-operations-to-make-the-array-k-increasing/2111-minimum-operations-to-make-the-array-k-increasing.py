class Solution:
    def find_ans(self , a) : 
        lis = []
        for i in a :
            idx = bisect_right(lis,i ); 
            if idx < len(lis):
                lis[idx] =i 
            else:
                lis.append(i);
        return len(lis) 
            
    def kIncreasing(self, a: List[int], k: int) -> int:
        n = len(a); 
        ans =0 ; 
        for i in range(k) :
            b = [a[j] for j in range(i , n , k )]
            ans += len(b) - self.find_ans(b)
        return ans