// Solution for Longest Palindrome by Concatenating Two Letter Words in JAVA

class Solution {
    public int longestPalindrome(String[] words) {
        Map<String, Integer> mp = new HashMap<>();
        for (String word : words) {
            mp.put(word, mp.getOrDefault(word, 0) + 1);
        }
        int res = 0;
        boolean centerUsed = false;
        for (String word : words) {
            String rev = new StringBuilder(word).reverse().toString();
            if (!word.equals(rev)) {
                if (mp.getOrDefault(word, 0) > 0 && mp.getOrDefault(rev, 0) > 0) {
                    mp.put(word, mp.get(word) - 1);
                    mp.put(rev, mp.get(rev) - 1);
                    res += 4;
                }
            } else {
                if (mp.get(word) >= 2) {
                    mp.put(word, mp.get(word) - 2);
                    res += 4;
                } else if (mp.get(word) == 1 && !centerUsed) {
                    mp.put(word, mp.get(word) - 1);
                    centerUsed = true;
                    res += 2;
                }
            }
        }
        return res;
    }
}
