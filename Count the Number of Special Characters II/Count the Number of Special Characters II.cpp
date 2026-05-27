// Solution for Count the Number of Special Characters II in CPP

class Solution {
public:
    int numberOfSpecialChars(string word) {

        // Stores the last occurrence index
        // of each lowercase character
        vector<int> lastLowercaseIndex(26, -1);

        // Stores the first occurrence index
        // of each uppercase character
        vector<int> firstUppercaseIndex(26, -1);

        for (int index = 0; index < word.size(); index++) {

            char currentCharacter = word[index];

            // Update latest position
            // of lowercase character
            if (islower(currentCharacter)) {

                lastLowercaseIndex[currentCharacter - 'a'] = index;
            }

            // Store only the first occurrence
            // of uppercase character
            else {

                if (firstUppercaseIndex[currentCharacter - 'A'] == -1) {

                    firstUppercaseIndex[currentCharacter - 'A'] = index;
                }
            }
        }

        int specialCharacterCount = 0;

        for (int alphabetIndex = 0; alphabetIndex < 26; alphabetIndex++) {

            // Character is special if:
            //
            // 1. Lowercase version exists
            // 2. Uppercase version exists
            // 3. Every lowercase occurrence appears
            //    before first uppercase occurrence
            if (lastLowercaseIndex[alphabetIndex] != -1 &&
                firstUppercaseIndex[alphabetIndex] != -1 &&
                lastLowercaseIndex[alphabetIndex] < firstUppercaseIndex[alphabetIndex]) {

                specialCharacterCount++;
            }
        }

        return specialCharacterCount;
    }
};
