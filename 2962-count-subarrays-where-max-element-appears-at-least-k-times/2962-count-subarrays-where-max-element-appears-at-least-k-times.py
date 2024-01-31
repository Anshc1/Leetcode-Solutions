class Solution:
    def update(self , x , p):
        if p in x:
            x[p]+=1
        else:
            x[p]= 1
    def countSubarrays(self, a: List[int], k: int) -> int: 
        j = 0;
        x = dict()
        mx = max(a)
        n = len(a)
        print(mx)
        x[mx] = 0 
        ans = 0 
        for i in range(0 , n ):
            self.update(x , a[i])
            while j < i :
                if x[mx] < k:
                    break
                if a[j] == mx and x[mx] == k:
                    break
                x[a[j]]-=1
                j+=1
            print(str(i) + " " + str(j))
            if x[mx] == k :
                ans += 1 +j
        return ans
            
                
            
        