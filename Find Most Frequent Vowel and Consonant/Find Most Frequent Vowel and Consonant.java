// Solution for Find Most Frequent Vowel and Consonant in JAVA

class Solution {
    public int maxFreqSum(String s) {
        int maxConsonantFreq = 0;
        int maxVowelFreq = 0;
        int[] frequency = new int[26]; // frequency for 'a' to 'z'

        for (char ch : s.toCharArray()) {
            frequency[ch - 'a']++;

            if ("aeiou".indexOf(ch) != -1) { // check if vowel
                maxVowelFreq = Math.max(maxVowelFreq, frequency[ch - 'a']);
            } else { // consonant
                maxConsonantFreq = Math.max(maxConsonantFreq, frequency[ch - 'a']);
            }
        }

        return maxConsonantFreq + maxVowelFreq;
    }
}
