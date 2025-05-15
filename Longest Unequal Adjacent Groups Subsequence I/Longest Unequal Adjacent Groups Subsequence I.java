// Solution for Longest Unequal Adjacent Groups Subsequence I in JAVA

class Solution {
    public List<String> getLongestSubsequence(String[] words, int[] groups) {
        List<String> res = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                res.add(words[i]);
            }
        }
        return res;
    }
}
