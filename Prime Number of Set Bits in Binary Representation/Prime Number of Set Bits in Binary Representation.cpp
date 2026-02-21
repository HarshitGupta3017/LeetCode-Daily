// Solution for Prime Number of Set Bits in Binary Representation in CPP

class Solution {
public:
    int countPrimeSetBits(int left, int right) {

        /*
            A number <= 10^6 has at most 20 bits.
            So number of set bits can be at most 20.

            Prime numbers <= 20 are:
            2, 3, 5, 7, 11, 13, 17, 19
        */
        unordered_set<int> primeSetBits = { 2, 3, 5, 7, 11, 13, 17, 19 };

        int count = 0;

        /*
            Check every number in range [left, right]
        */
        for (int num = left; num <= right; num++) {

            /*
                __builtin_popcount(num)
                returns number of 1's in binary representation.
            */
            int setBits = __builtin_popcount(num);

            /*
                If setBits is prime,
                increment answer.
            */
            if (primeSetBits.count(setBits)) {
                count++;
            }
        }

        return count;
    }
};
