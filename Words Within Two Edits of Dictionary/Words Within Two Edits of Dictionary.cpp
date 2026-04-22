// Solution for Words Within Two Edits of Dictionary in CPP

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {

        vector<string> matchingWords;

        // Iterate over each query word
        for (const string& queryWord : queries) {

            // Compare with each dictionary word
            for (const string& dictWord : dictionary) {

                int mismatchCount = 0;

                // Count character differences
                for (int index = 0; index < queryWord.size(); index++) {

                    if (queryWord[index] != dictWord[index]) {
                        mismatchCount++;
                    }

                    // Early exit if more than 2 edits required
                    if (mismatchCount > 2)
                        break;
                }

                // If within allowed edits, add to result
                if (mismatchCount <= 2) {
                    matchingWords.push_back(queryWord);
                    break; // No need to check further dictionary words
                }
            }
        }

        return matchingWords;
    }
};
