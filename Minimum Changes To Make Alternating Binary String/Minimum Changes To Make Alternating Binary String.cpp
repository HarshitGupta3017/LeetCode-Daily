// Solution for Minimum Changes To Make Alternating Binary String in CPP

class Solution {
public:
    int minOperations(string s) {

        /*
            Length of the binary string
        */
        int stringLength = s.size();

        /*
            flipsStartingWithZero:
            Counts number of flips required if the alternating
            pattern starts with '0'.

            Expected pattern:
            index: 0 1 2 3 4
            value: 0 1 0 1 0
        */
        int flipsStartingWithZero = 0;

        /*
            Traverse each character and check whether
            it matches the expected alternating pattern.
        */
        for (int index = 0; index < stringLength; index++) {

            /*
                For pattern starting with '0':

                Even index -> expected '0'
                Odd index  -> expected '1'

                If actual character differs from expected,
                we must flip it.
            */
            if ((index % 2 == 0 && s[index] == '1') || 
                (index % 2 == 1 && s[index] == '0')) {

                flipsStartingWithZero++;
            }
        }

        /*
            If we start pattern with '1', the pattern becomes:

            1 0 1 0 1 0 ...

            Positions that matched the previous pattern
            will mismatch this one.

            Therefore flips needed = remaining positions.
        */
        int flipsStartingWithOne = stringLength - flipsStartingWithZero;

        /*
            Return the minimum flips required between
            the two possible alternating patterns.
        */
        return min(flipsStartingWithZero, flipsStartingWithOne);
    }
};
