public class Solution {
    public String findLongestWord(String s, List<String> a) {
        int n = a.size();
        int m = s.length();
        int[] idx = new int[n];
        int[] ct = new int[n];
        int mx = 0;
        List<String> x = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i < s.length() && idx[j] < a.get(j).length() && s.charAt(i) == a.get(j).charAt(idx[j])) {
                    idx[j]++;
                }
                if (idx[j] == a.get(j).length()) {
                    mx = Math.max(mx, a.get(j).length());
                    x.add(a.get(j));
                }
            }
        }
        if (mx == 0) {
            return "";
        }

        String ans = String.format("%1$-" + 1005 + "s", "z").replace(' ', 'z');
        for (String i : x) {
            if (i.length() == mx) {
                ans = (ans.compareTo(i) < 0) ? ans : i;
            }
        }
        return ans;
    }
}