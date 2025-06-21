// Solution for Minimum Deletions to Make String K-Special in JAVA

class Solution {
    public int minimumDeletions(String word, int k) {
        int[] freq = new int[26];

        for (char ch : word.toCharArray()) {
            freq[ch - 'a']++;
        }

        Arrays.sort(freq);
        int minDeletions = Integer.MAX_VALUE;
        int cumulativeDeletions = 0;

        for (int i = 0; i < 26; i++) {
            int deletionsNeeded = cumulativeDeletions;

            for (int j = 25; j > i; j--) {
                if (freq[j] - freq[i] <= k) break;
                deletionsNeeded += freq[j] - freq[i] - k;
            }

            minDeletions = Math.min(minDeletions, deletionsNeeded);
            cumulativeDeletions += freq[i];
        }

        return minDeletions;
    }
}
