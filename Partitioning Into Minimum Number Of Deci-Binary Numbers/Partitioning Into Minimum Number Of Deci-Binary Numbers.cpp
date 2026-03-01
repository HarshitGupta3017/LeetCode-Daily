// Solution for Partitioning Into Minimum Number Of Deci-Binary Numbers in CPP

class Solution {
public:
    int minPartitions(string n) {

        /*
            Each deci-binary number can contribute
            at most 1 to any digit position.

            So if at some position digit = d,
            we need at least d deci-binary numbers
            to build that column.

            Therefore, the answer must be at least
            the maximum digit in n.
        */

        /*
            Good news:
            It is always possible to construct exactly
            'maximum digit' deci-binary numbers that sum to n.

            So the minimum number required is simply
            the maximum digit in the string.
        */

        // Find maximum digit character
        char maximumDigitCharacter = *max_element(n.begin(), n.end());

        // Convert char to integer
        int maximumDigitValue = maximumDigitCharacter - '0';

        return maximumDigitValue;
    }
};
