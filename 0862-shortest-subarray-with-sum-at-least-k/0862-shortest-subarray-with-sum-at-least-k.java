public class Solution {
    public int shortestSubarray(int[] a, int k) {
        int n = a.length;
        long[] pref = new long[n + 1];
        
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        
        int ans = Integer.MAX_VALUE;
        Deque<Integer> q = new LinkedList<>();
        
        for (int i = 0; i < n; i++) {
            if (pref[i + 1] >= k) {
                ans = Math.min(ans, i + 1);
            }
            while (!q.isEmpty() && pref[i + 1] - pref[q.peekFirst()] >= k) {
                ans = Math.min(ans, i - q.pollFirst() + 1);
            }
            while (!q.isEmpty() && pref[i + 1] < pref[q.peekLast()]) {
                q.pollLast();
            }
            q.offerLast(i + 1);
        }
        
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
