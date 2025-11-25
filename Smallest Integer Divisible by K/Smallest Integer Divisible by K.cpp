// Solution for Smallest Integer Divisible by K in CPP

class Solution {
public:
    int smallestRepunitDivByK(int k) {

        // If k has factor 2 or 5, no number made of only '1's can be divisible by k.
        // Because repunits end with digit 1 → not divisible by 2 or 5.
        if (k % 2 == 0 || k % 5 == 0) return -1;

        int remainder = 0;  // This will track the current repunit % k.

        /*
            We build repunits incrementally:
                1
                11
                111
                1111   ... etc.

            But instead of storing the whole number (huge),
            we only store remainder:

                newNumber = oldNumber * 10 + 1
                newRemainder = (oldRemainder * 10 + 1) % k

            Why loop only k times?
            Pigeonhole principle:
            There are only k possible remainders (0 to k-1).
            If we don't hit remainder 0 within k steps,
            we will loop forever → no valid repunit.
        */

        for (int length = 1; length <= k; length++) {

            // Append '1' to the repunit and update remainder.
            remainder = (remainder * 10 + 1) % k;

            // If remainder becomes 0 → the number is divisible by k.
            if (remainder == 0)
                return length;
        }

        return -1;  // No repunit divisible by k exists.
    }
};
