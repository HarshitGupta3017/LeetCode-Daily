// Solution for Complement of Base 10 Integer in CPP

class Solution {
public:
    int bitwiseComplement(int n) {

        /*
            Special case:
            If n = 0, its binary representation is "0".
            Flipping it gives "1".
        */
        if (n == 0)
            return 1;

        /*
            Find number of bits in n.
            log2(n) gives index of highest set bit.
            +1 gives total bit length.
        */
        int bitLength = (int)log2(n) + 1;

        /*
            Create a mask with all bits set to 1
            of the same length.

            Example:
            bitLength = 3
            mask = (1 << 3) - 1 = 8 - 1 = 7
            binary: 111
        */
        int mask = (1 << bitLength) - 1;

        /*
            XOR flips the bits.
        */
        return n ^ mask;
    }
};
