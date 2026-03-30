// Solution for Check if Strings Can be Made Equal With Operations II in CPP

class Solution {
public:
    bool checkStrings(string s1, string s2) {

        int n = s1.size();

        /*
            evenFreq[ch] → difference of frequency of character 'ch'
                           at EVEN indices (s1 - s2)

            oddFreq[ch]  → same but for ODD indices
        */
        vector<int> evenFreq(26, 0);
        vector<int> oddFreq(26, 0);

        /*
            Traverse both strings simultaneously

            Allowed operation:
            - You can swap indices i, j ONLY if (j - i) is EVEN
            → That means:
                even index ↔ even index
                odd index  ↔ odd index

            ❗ So:
            - Characters at EVEN positions can ONLY rearrange among EVEN positions
            - Characters at ODD positions can ONLY rearrange among ODD positions

            ⇒ We must match frequency separately for even and odd indices
        */
        for (int i = 0; i < n; i++) {

            if (i % 2 == 0) {
                // Track frequency difference at EVEN positions
                evenFreq[s1[i] - 'a']++;   // add from s1
                evenFreq[s2[i] - 'a']--;   // subtract from s2
            } 
            else {
                // Track frequency difference at ODD positions
                oddFreq[s1[i] - 'a']++;
                oddFreq[s2[i] - 'a']--;
            }
        }

        /*
            If both strings can be made equal,
            all frequency differences must cancel out
        */
        for (int ch = 0; ch < 26; ch++) {
            if (evenFreq[ch] != 0 || oddFreq[ch] != 0) {
                return false;
            }
        }

        return true;
    }
};
