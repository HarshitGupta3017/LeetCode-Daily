// Solution for Lexicographically Smallest Generated String in CPP

class Solution {
public:

    /*
        Helper:
        Check if substring word[start ... start+m-1] == str2
    */
    bool isSame(string& word, string& str2, int start, int m) {

        for (int j = 0; j < m; j++) {
            if (word[start + j] != str2[j]) {
                return false;
            }
        }
        return true;
    }

    string generateString(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        /*
            Final word length:
            For each i, substring of size m starts → total = n + m - 1
        */
        int totalLen = n + m - 1;

        // Initialize with placeholder
        string word(totalLen, '$');

        /*
        ============================================================
        STEP 1: FORCE all 'T' constraints
        ============================================================

        If str1[i] == 'T':
        → word[i ... i+m-1] MUST equal str2

        We fill those positions directly.
        If conflict occurs → impossible
        */
        for (int i = 0; i < n; i++) {

            if (str1[i] == 'T') {

                int pos = i;

                for (int j = 0; j < m; j++) {

                    // If already filled and mismatching → impossible
                    if (word[pos] != '$' && word[pos] != str2[j]) {
                        return "";
                    }

                    word[pos] = str2[j];
                    pos++;
                }
            }
        }

        /*
        ============================================================
        STEP 2: Fill remaining positions with 'a'
        ============================================================

        Why 'a'?
        → To ensure lexicographically smallest result

        Also track which positions are flexible (can change later)
        */
        vector<bool> canModify(totalLen, false);

        for (int i = 0; i < totalLen; i++) {
            if (word[i] == '$') {
                word[i] = 'a';       // smallest possible
                canModify[i] = true; // can tweak later if needed
            }
        }

        /*
        ============================================================
        STEP 3: Handle 'F' constraints
        ============================================================

        If str1[i] == 'F':
        → substring word[i ... i+m-1] MUST NOT equal str2

        If currently equal:
            we must BREAK it by changing at least ONE character
        */
        for (int i = 0; i < n; i++) {

            if (str1[i] == 'F') {

                // If currently violating (equal to str2)
                if (isSame(word, str2, i, m)) {

                    bool changed = false;

                    /*
                        Strategy:
                        Modify RIGHTMOST possible position

                        WHY rightmost?
                        → Keeps lexicographically smallest prefix intact
                    */
                    for (int j = i + m - 1; j >= i; j--) {

                        if (canModify[j]) {

                            word[j] = 'b'; // minimal change to break equality
                            changed = true;
                            break;
                        }
                    }

                    // If no modifiable position → impossible
                    if (!changed) return "";
                }
            }
        }

        return word;
    }
};
