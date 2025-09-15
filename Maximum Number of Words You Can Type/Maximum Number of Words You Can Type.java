// Solution for Maximum Number of Words You Can Type in JAVA

class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        // Step 1: Track which letters are broken using a boolean array
        boolean[] isBroken = new boolean[26];
        for (char ch : brokenLetters.toCharArray()) {
            isBroken[ch - 'a'] = true;
        }

        int fullyTypableCount = 0;   // Count of words that can be typed
        boolean canTypeCurrentWord = true;  // Track if current word is typable

        // Step 2: Traverse each character in the given text
        for (char ch : text.toCharArray()) {
            if (ch == ' ') {
                if (canTypeCurrentWord) {
                    fullyTypableCount++;
                }
                canTypeCurrentWord = true; // Reset for next word
            } else if (isBroken[ch - 'a']) {
                canTypeCurrentWord = false;
            }
        }

        // Step 3: Handle the last word
        if (canTypeCurrentWord) {
            fullyTypableCount++;
        }

        return fullyTypableCount;
    }
}
