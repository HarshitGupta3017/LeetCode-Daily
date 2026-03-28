// Solution for Find the String with LCP in JAVA

class Solution {

    // Helper function to rebuild LCP matrix
    public int[][] buildLCP(String word) {
        int n = word.length();
        int[][] computedLCP = new int[n][n];

        // Base case
        for (int i = 0; i < n; i++) {
            computedLCP[i][n - 1] = (word.charAt(i) == word.charAt(n - 1)) ? 1 : 0;
        }

        for (int j = 0; j < n; j++) {
            computedLCP[n - 1][j] = (word.charAt(n - 1) == word.charAt(j)) ? 1 : 0;
        }

        // Fill bottom-up
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (word.charAt(i) == word.charAt(j)) {
                    computedLCP[i][j] = 1 + computedLCP[i + 1][j + 1];
                } else {
                    computedLCP[i][j] = 0;
                }
            }
        }

        return computedLCP;
    }

    public String findTheString(int[][] lcp) {
        int n = lcp.length;

        // Step 1: initialize
        char[] word = new char[n];
        Arrays.fill(word, '$');

        // Step 2: construct string
        for (int i = 0; i < n; i++) {

            // Try reuse
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] != 0) {
                    word[i] = word[j];
                    break;
                }
            }

            // Assign new character
            if (word[i] == '$') {
                boolean[] forbidden = new boolean[26];

                for (int j = 0; j < i; j++) {
                    if (lcp[i][j] == 0) {
                        forbidden[word[j] - 'a'] = true;
                    }
                }

                for (int ch = 0; ch < 26; ch++) {
                    if (!forbidden[ch]) {
                        word[i] = (char) ('a' + ch);
                        break;
                    }
                }

                if (word[i] == '$') return "";
            }
        }

        String result = new String(word);

        // Step 3: validate
        return Arrays.deepEquals(buildLCP(result), lcp) ? result : "";
    }
}
