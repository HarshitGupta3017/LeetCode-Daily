// Solution for Reverse Degree of a String in JAVA

class Solution {
    public int reverseDegree(String s) {
        int ans = 0;

        for (int i = 1; i <= s.length(); i++) {
            ans += (26 - (s.charAt(i - 1) - 'a')) * i;
        }

        return ans;
    }
}
