// Solution for Maximum Number of Words You Can Type in CPP

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // Step 1: Track which letters are broken using a boolean array
        vector<bool> isBroken(26, false);
        for (char ch : brokenLetters) {
            isBroken[ch - 'a'] = true;  
        }

        int fullyTypableCount = 0;  // Count of words that can be typed
        bool canTypeCurrentWord = true;  // Track if the current word is typable

        // Step 2: Traverse each character in the given text
        for (char ch : text) {
            if (ch == ' ') {
                // End of a word → if word was typable, increment count
                if (canTypeCurrentWord) {
                    fullyTypableCount++;
                }
                // Reset flag for the next word
                canTypeCurrentWord = true;  
            } else if (isBroken[ch - 'a']) {
                // Current word contains a broken letter → cannot be typed
                canTypeCurrentWord = false;  
            }
        }

        // Step 3: Handle the last word (since it won’t end with a space)
        if (canTypeCurrentWord) {
            fullyTypableCount++;
        }

        return fullyTypableCount;
    }
};
