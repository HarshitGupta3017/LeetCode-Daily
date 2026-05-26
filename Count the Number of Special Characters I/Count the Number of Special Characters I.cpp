// Solution for Count the Number of Special Characters I in CPP

class Solution {
public:
    int numberOfSpecialChars(string word) {

        // Tracks presence of lowercase letters
        vector<bool> lowercasePresent(26, false);

        // Tracks presence of uppercase letters
        vector<bool> uppercasePresent(26, false);

        // Mark occurrence of each character
        for (const char& character : word) {

            // Store lowercase character presence
            if (islower(character)) {

                lowercasePresent[character - 'a'] = true;
            }

            // Store uppercase character presence
            else {

                uppercasePresent[character - 'A'] = true;
            }
        }

        int specialCharacterCount = 0;

        // A character is considered special
        // if both lowercase and uppercase forms exist
        for (int alphabetIndex = 0; alphabetIndex < 26; alphabetIndex++) {

            if (lowercasePresent[alphabetIndex] && uppercasePresent[alphabetIndex]) {

                specialCharacterCount++;
            }
        }

        return specialCharacterCount;
    }
};
