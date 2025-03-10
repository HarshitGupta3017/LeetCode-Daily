// Solution for Count of Substrings Containing Every Vowel and K Consonants II in JAVA

class Solution {
    public long countOfSubstrings(String word, int k) {
        int n = word.length();
        Set<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));
        Map<Character, Integer> mp = new HashMap<>(); // vowelsCount
        int[] nextConsonant = new int[n];
        int lastConsIdx = n; // consonant index
        for (int i = n - 1; i >= 0; i--) {
            nextConsonant[i] = lastConsIdx;
            if (!vowels.contains(word.charAt(i))) {
                lastConsIdx = i;
            }
        }
        int i = 0, j = 0, cons = 0;
        long res = 0;
        while (j < n) {
            if (vowels.contains(word.charAt(j))) {
                mp.put(word.charAt(j), mp.getOrDefault(word.charAt(j), 0) + 1);
            } else {
                cons++;
            }
            while (cons > k) {
                char ch = word.charAt(i);
                if (vowels.contains(ch)) {
                    mp.put(ch, mp.get(ch) - 1);
                    if (mp.get(ch) == 0) mp.remove(ch);
                } else {
                    cons--;
                }
                i++;
            }
            while (i < n && mp.size() == 5 && cons == k) {
                res += (nextConsonant[j] - j);
                char ch = word.charAt(i);
                if (vowels.contains(ch)) {
                    mp.put(ch, mp.get(ch) - 1);
                    if (mp.get(ch) == 0) mp.remove(ch);
                } else {
                    cons--;
                }
                i++;
            }
            j++;
        }
        return res;
    }
}
