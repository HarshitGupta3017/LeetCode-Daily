// Solution for Longest Balanced Substring II in CPP

class Solution {
public:

    /*
        Helper function:
        Finds longest balanced substring
        containing ONLY ch1 and ch2.

        Balanced condition for 2 chars:
        count(ch1) == count(ch2)
    */
    int longestTwoCharBalanced(string& s, char ch1, char ch2) {

        int count1 = 0;   // frequency of ch1
        int count2 = 0;   // frequency of ch2
        int maxLength = 0;

        /*
            Stores first occurrence of each difference:
            diff = count1 - count2

            If same diff appears again,
            subarray between those indices has equal counts.
        */
        unordered_map<int, int> firstSeenDiff;

        for (int i = 0; i < s.size(); i++) {

            /*
                If character is not part of this pair,
                reset everything.
            */
            if (s[i] != ch1 && s[i] != ch2) {
                firstSeenDiff.clear();
                count1 = 0;
                count2 = 0;
                continue;
            }

            if (s[i] == ch1) count1++;
            else count2++;

            /*
                If counts equal directly,
                substring from beginning is balanced.
            */
            if (count1 == count2) {
                maxLength = max(maxLength, count1 + count2);
            }

            int diff = count1 - count2;

            /*
                If same diff appeared before,
                substring between them has equal counts.
            */
            if (firstSeenDiff.count(diff)) {
                maxLength = max(maxLength, i - firstSeenDiff[diff]);
            } else {
                firstSeenDiff[diff] = i;
            }
        }

        return maxLength;
    }

    int longestBalanced(string s) {

        int n = s.size();
        int maxLength = 0;

        /*
            -----------------------------
            Case 1: Only ONE distinct char
            -----------------------------

            Any continuous block of same character
            is automatically balanced.
        */
        int streakLength = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                streakLength++;
            } else {
                maxLength = max(maxLength, streakLength);
                streakLength = 1;
            }
        }
        maxLength = max(maxLength, streakLength);

        /*
            -----------------------------
            Case 2: Exactly TWO distinct chars
            -----------------------------
        */
        maxLength = max(maxLength, longestTwoCharBalanced(s, 'a', 'b'));
        maxLength = max(maxLength, longestTwoCharBalanced(s, 'a', 'c'));
        maxLength = max(maxLength, longestTwoCharBalanced(s, 'b', 'c'));

        /*
            -----------------------------
            Case 3: All THREE chars
            -----------------------------

            Balanced condition:
            countA == countB == countC

            Equivalent to:
            (countA - countB == 0)
            AND
            (countA - countC == 0)

            So we track pair:
            (diffAB, diffAC)
        */
        int countA = 0, countB = 0, countC = 0;

        /*
            Map stores first occurrence of each (diffAB, diffAC).
            We encode pair as string key.
        */
        unordered_map<string, int> firstSeenState;

        for (int i = 0; i < n; i++) {

            if (s[i] == 'a') countA++;
            else if (s[i] == 'b') countB++;
            else countC++;

            /*
                If all counts equal directly
            */
            if (countA == countB && countA == countC) {
                maxLength = max(maxLength, countA + countB + countC);
            }

            int diffAB = countA - countB;
            int diffAC = countA - countC;

            string stateKey =
                to_string(diffAB) + "_" + to_string(diffAC);

            /*
                If same state occurred before,
                substring between them is balanced.
            */
            if (firstSeenState.count(stateKey)) {
                maxLength = max(maxLength,
                                i - firstSeenState[stateKey]);
            } else {
                firstSeenState[stateKey] = i;
            }
        }

        return maxLength;
    }
};
