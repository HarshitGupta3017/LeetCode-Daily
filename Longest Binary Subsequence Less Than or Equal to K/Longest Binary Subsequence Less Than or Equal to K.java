// Solution for Longest Binary Subsequence Less Than or Equal to K in JAVA

class Solution {
    public int longestSubsequence(String s, int k) {
        int n = s.length();
        long powerOfTwo = 1;  
        int maxLength = 0;       

        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == '0') {
                maxLength++;
            } else if (powerOfTwo <= k) {
                k -= powerOfTwo;
                maxLength++;
            }
            if (powerOfTwo <= k) {
                powerOfTwo <<= 1; 
            }
        }
        return maxLength;
    }
}
