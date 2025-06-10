// Solution for Maximum Difference Between Even and Odd Frequency I in JAVA

class Solution {
    public int maxDifference(String s) {
        int[] charFreq = new int[26];
        for (char ch : s.toCharArray()) {
            charFreq[ch - 'a']++;
        }
        
        int maxOddFreq = 0;
        int minEvenFreq = Integer.MAX_VALUE;
        
        for (int i = 0; i < 26; i++) {
            if (charFreq[i] == 0) continue; 
            
            if (charFreq[i] % 2 == 0) {
                minEvenFreq = Math.min(minEvenFreq, charFreq[i]);
            } else {
                maxOddFreq = Math.max(maxOddFreq, charFreq[i]);
            }
        }
        
        return maxOddFreq - minEvenFreq;
    }
}
