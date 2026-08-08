// Solution for Find the Lexicographically Smallest Valid Sequence in JAVA

class Solution {
    public int[] validSequence(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();

        // suffixMatchCount[i] = number of characters of word2
        // that can be matched by scanning word1[i..n-1] from right to left.
        int[] suffixMatchCount = new int[n];

        int suffixMatched = 0;
        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1.charAt(i) == word2.charAt(j)) {
                suffixMatched++;
                j--;
            }
            suffixMatchCount[i] = suffixMatched;
        }

        // Greedily build the index sequence from left to right.
        int[] temp = new int[m];
        int size = 0;

        boolean canUseMismatch = true;
        j = 0;

        for (int i = 0; i < n && j < m; i++) {
            if (word1.charAt(i) == word2.charAt(j)) {
                // Exact match
                temp[size++] = i;
                j++;
            } 
            else if (canUseMismatch
                    && i + 1 < n
                    && suffixMatchCount[i + 1] >= m - j - 1) {

                // Use the one allowed substitution
                temp[size++] = i;
                j++;
                canUseMismatch = false;
            }
        }

        if (j != m) {
            return new int[0];
        }

        int[] result = new int[size];
        System.arraycopy(temp, 0, result, 0, size);
        return result;
    }
}
