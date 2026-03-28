// Solution for Find the String with LCP in CPP

class Solution {
public:

    /*
        Helper function:
        Rebuild the LCP matrix from a constructed string
        → Used to VERIFY if our constructed string is valid
    */
    vector<vector<int>> buildLCP(string& word) {

        int n = word.size();

        // lcp[i][j] = longest common prefix of suffixes starting at i and j
        vector<vector<int>> computedLCP(n, vector<int>(n, 0));

        /*
            Base case:
            Last column / last row
            Only 1 character comparison possible
        */
        for (int i = 0; i < n; i++) {
            computedLCP[i][n - 1] = (word[i] == word[n - 1]) ? 1 : 0;
        }

        for (int j = 0; j < n; j++) {
            computedLCP[n - 1][j] = (word[n - 1] == word[j]) ? 1 : 0;
        }

        /*
            Fill remaining matrix bottom-up

            If characters match:
                lcp[i][j] = 1 + lcp[i+1][j+1]
            Else:
                lcp[i][j] = 0
        */
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {

                if (word[i] == word[j]) {
                    computedLCP[i][j] = 1 + computedLCP[i + 1][j + 1];
                } else {
                    computedLCP[i][j] = 0;
                }
            }
        }

        return computedLCP;
    }

    string findTheString(vector<vector<int>>& lcp) {

        int n = lcp.size();

        /*
            STEP 1: Initialize result string with placeholders
        */
        string word(n, '$');

        /*
            STEP 2: Construct the string

            Idea:
            If lcp[i][j] > 0 → word[i] == word[j]
        */
        for (int i = 0; i < n; i++) {

            /*
                Try to reuse an already assigned character
                based on LCP condition
            */
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] != 0) {
                    word[i] = word[j];
                    break;
                }
            }

            /*
                If still not assigned → assign smallest valid char
            */
            if (word[i] == '$') {

                vector<bool> forbidden(26, false);

                /*
                    Mark characters that cannot be used

                    If lcp[i][j] == 0:
                    → word[i] != word[j]
                */
                for (int j = 0; j < i; j++) {
                    if (lcp[i][j] == 0) {
                        forbidden[word[j] - 'a'] = true;
                    }
                }

                /*
                    Pick smallest lexicographic character
                */
                for (int ch = 0; ch < 26; ch++) {
                    if (!forbidden[ch]) {
                        word[i] = char('a' + ch);
                        break;
                    }
                }

                /*
                    If no character possible → invalid case
                */
                if (word[i] == '$') return "";
            }
        }

        /*
            STEP 3: Validate constructed string

            Important because greedy construction
            may produce incorrect structure
        */
        return (buildLCP(word) == lcp) ? word : "";
    }
};
