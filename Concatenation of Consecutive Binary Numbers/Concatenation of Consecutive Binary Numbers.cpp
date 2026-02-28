// Solution for Concatenation of Consecutive Binary Numbers in CPP

class Solution {
public:
    int concatenatedBinary(int n) {

        /*
            We will build the answer progressively.

            finalNumber represents the decimal value
            of the concatenated binary string so far.
        */
        long long finalNumber = 0;

        const int MOD = 1e9 + 7;

        /*
            We iterate from 1 to n,
            and append each number's binary representation
            to the current result.
        */
        for (int currentNumber = 1; currentNumber <= n; currentNumber++) {

            /*
                Compute how many bits are needed
                to represent currentNumber in binary.

                bits = floor(log2(currentNumber)) + 1
            */
            int numberOfBits = log2(currentNumber) + 1;

            /*
                Appending binary is equivalent to:

                1) Shift existing result left by numberOfBits
                   (making space for the new binary digits)

                2) Add currentNumber

                IMPORTANT:
                We take modulo after shifting to prevent overflow.
            */
            finalNumber = ((finalNumber << numberOfBits) % MOD + currentNumber) % MOD;
        }

        return finalNumber;
    }
};
