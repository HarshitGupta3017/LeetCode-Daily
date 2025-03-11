// Solution for Number of Substrings Containing All Three Characters in JAVA

class Solution {
    public int numberOfSubstrings(String s) {
        int i = 0, j = 0, res = 0;
        int n = s.length();
        Map<Character, Integer> mp = new HashMap<>();
        while (j < n) {
            mp.put(s.charAt(j), mp.getOrDefault(s.charAt(j), 0) + 1);
            while (mp.size() == 3) {
                res += n - j;
                char ch = s.charAt(i);
                mp.put(ch, mp.get(ch) - 1);
                if (mp.get(ch) == 0) mp.remove(ch);
                i++;
            }
            j++;
        }
        return res;
    }
}
