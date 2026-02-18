// Solution for Binary Number with Alternating Bits in CPP

class Solution {
public:
    bool hasAlternatingBits(int n) {

        /*
            If bits alternate like:
            101010...

            Then:
            n >> 1 becomes:
            010101...

            XOR of them gives:
            111111...  (all 1s)
        */

        unsigned int xorResult = n ^ (n >> 1);

        /*
            If xorResult is of form:
            11111... (all 1s)

            That means bits are alternate
            Then (xorResult & (xorResult + 1)) == 0

            Because:
            Example:
            x = 11111 (binary)

            x + 1 = 100000
            AND → 000000
        */

        return (xorResult & (xorResult + 1)) == 0;
    }
};
