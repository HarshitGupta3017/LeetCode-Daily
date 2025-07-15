// Solution for Valid Word in CPP

class Solution {
public:
    bool isValid(string word) {
        // Word must be at least 3 characters long
        if (word.length() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char ch : word) {
            ch = tolower(ch); // Normalize to lowercase

            if (isalpha(ch)) {
                // Check for vowels
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
            else if (!isdigit(ch)) {
                // If it's neither a letter nor a digit, it's invalid
                return false;
            }
        }

        // Valid only if it has at least one vowel and one consonant
        return hasVowel && hasConsonant;
    }
};
