// Solution for Lexicographically Smallest Generated String in JAVA

class Solution {

    // Helper function
    boolean isSame(String word, String str2, int start, int m) {
        for (int j = 0; j < m; j++) {
            if (word.charAt(start + j) != str2.charAt(j)) {
                return false;
            }
        }
        return true;
    }

    public String generateString(String str1, String str2) {

        int n = str1.length();
        int m = str2.length();

        int totalLen = n + m - 1;

        char[] word = new char[totalLen];
        for (int i = 0; i < totalLen; i++) word[i] = '$';

        // STEP 1: Handle 'T'
        for (int i = 0; i < n; i++) {
            if (str1.charAt(i) == 'T') {
                for (int j = 0; j < m; j++) {
                    int pos = i + j;

                    if (word[pos] != '$' && word[pos] != str2.charAt(j)) {
                        return "";
                    }
                    word[pos] = str2.charAt(j);
                }
            }
        }

        // STEP 2: Fill remaining with 'a'
        boolean[] canModify = new boolean[totalLen];
        for (int i = 0; i < totalLen; i++) {
            if (word[i] == '$') {
                word[i] = 'a';
                canModify[i] = true;
            }
        }

        String current = new String(word);

        // STEP 3: Handle 'F'
        for (int i = 0; i < n; i++) {
            if (str1.charAt(i) == 'F') {

                if (isSame(current, str2, i, m)) {

                    boolean changed = false;

                    for (int j = i + m - 1; j >= i; j--) {
                        if (canModify[j]) {
                            word[j] = 'b';
                            changed = true;
                            break;
                        }
                    }

                    if (!changed) return "";

                    current = new String(word);
                }
            }
        }

        return new String(word);
    }
}
