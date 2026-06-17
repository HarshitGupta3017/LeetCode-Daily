// Solution for Process String with Special Operations II in CPP

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        // Forward pass: track only the final length of result, not its actual
        // contents. Building the real string would be exponential in size
        // because of repeated '#' duplications, so we simulate length only.
        long long finalLen = 0;

        for (char ch : s) {
            if (ch == '*') {
                if (finalLen > 0) finalLen--;
            } else if (ch == '%') {
                // Reversal doesn't change the length, only the order of characters.
                continue;
            } else if (ch == '#') {
                finalLen *= 2;
            } else {
                finalLen++;
            }
        }

        // If k falls outside the final string entirely, no amount of backward
        // simulation will find it.
        if (k >= finalLen) return '.';

        // Backward pass: walk the operations in reverse, undoing each one's
        // effect on the length while tracking where index k "came from" at
        // each prior step. This lets us trace k all the way back to the exact
        // character that was appended at that position, without ever
        // materialising the actual string.
        long long lenSoFar = finalLen;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '*') {
                // Undoing a deletion means the result was one character longer
                // just before this point.
                lenSoFar++;
            } else if (s[i] == '%') {
                // Undoing a reversal: position k in the reversed string
                // corresponds to position (lenSoFar - k - 1) in the
                // pre-reversal string.
                k = lenSoFar - k - 1;
            } else if (s[i] == '#') {
                // Undoing a duplication: the string was half as long before
                // this step. If k falls in the second half (the copy), it
                // maps to the same offset in the first half.
                lenSoFar /= 2;
                if (k >= lenSoFar) k -= lenSoFar;
            } else {
                // Undoing a letter append: the string was one character
                // shorter before this point.
                lenSoFar--;
            }

            // If k now points exactly at the position this letter was
            // appended to (the last index of the string at this step),
            // we've found our answer.
            if (k == lenSoFar) {
                return s[i];
            }
        }

        return '.';
    }
};
