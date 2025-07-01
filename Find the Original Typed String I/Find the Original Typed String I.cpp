// Solution for Find the Original Typed String I in CPP

class Solution {
public:
    int possibleStringCount(string word) {
        int repeatCount = 0;

        // Count how many adjacent characters are the same
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == word[i - 1]) {
                repeatCount++;
            }
        }

        // Alice could have long-pressed any of these repeated characters once
        // Plus 1 for the possibility that she typed everything correctly
        return repeatCount + 1;
    }
};
