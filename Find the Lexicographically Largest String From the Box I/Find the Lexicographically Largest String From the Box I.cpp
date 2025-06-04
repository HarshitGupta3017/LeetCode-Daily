// Solution for Find the Lexicographically Largest String From the Box I in CPP

class Solution {
public:
    string answerString(string word, int numFriends) {
        // If there's only one friend, the entire word is the only possible answer
        if (numFriends == 1) return word;

        int totalLength = word.length();

        // Maximum length any single part can have while still being able to split
        // the rest of the word into (numFriends - 1) non-empty parts
        int maxChunkLength = totalLength - (numFriends - 1);

        string maxString = "";  // Stores the lexicographically largest substring found

        // Try all possible substrings starting at each index
        for (int start = 0; start < totalLength; start++) {
            // The length we can take from this position without violating constraints
            int currentChunkLength = min(maxChunkLength, totalLength - start);

            // Extract substring and update maxString if it's lexicographically larger
            string currentSubstring = word.substr(start, currentChunkLength);
            maxString = max(maxString, currentSubstring);
        }

        return maxString;
    }
};
