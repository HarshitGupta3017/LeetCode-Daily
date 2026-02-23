// Solution for Check If a String Contains All Binary Codes of Size K in CPP

class Solution {
public:
    bool hasAllCodes(string s, int k) {

        /*
            Total possible binary strings of length k
            = 2^k
        */
        int totalCodesNeeded = 1 << k;

        /*
            This set will store unique substrings
            of length k found in s.
        */
        unordered_set<string> seen;

        /*
            Slide a window of size k
            across the string.
        */
        for (int i = k; i <= s.size(); i++) {

            /*
                Extract substring of length k
                ending at index i-1
            */
            string sub = s.substr(i - k, k);

            /*
                If we haven't seen this substring before,
                insert it and reduce required count.
            */
            if (!seen.count(sub)) {
                seen.insert(sub);
                totalCodesNeeded--;
            }

            /*
                If we collected all 2^k codes,
                return true immediately.
            */
            if (totalCodesNeeded == 0)
                return true;
        }

        /*
            If after scanning entire string
            we didn't collect all codes,
            return false.
        */
        return false;
    }
};
