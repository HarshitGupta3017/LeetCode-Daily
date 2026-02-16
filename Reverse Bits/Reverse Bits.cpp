// Solution for Reverse Bits in CPP

class Solution {
public:
    int reverseBits(int n) {

        int reversed = 0;

        /*
            We process exactly 32 bits.
        */
        for (int i = 0; i < 32; i++) {

            /*
                Step 1:
                Shift result left to make space
                for the next bit.
            */
            reversed <<= 1;

            /*
                Step 2:
                Extract the last bit of number
                using (number & 1)
            */
            reversed |= (n & 1);

            /*
                Step 3:
                Shift number right
                to process next bit.
            */
            n >>= 1;
        }

        return reversed;
    }
};
