// Solution for Minimum Changes To Make Alternating Binary String in JAVA

class Solution {
    public int minOperations(String s) {

        // Length of the binary string
        int stringLength = s.length();

        /*
            flipsStartingWithZero:
            Counts flips needed if pattern starts with '0'

            Expected pattern:
            index: 0 1 2 3 4
            value: 0 1 0 1 0
        */
        int flipsStartingWithZero = 0;

        // Traverse the string
        for (int index = 0; index < stringLength; index++) {

            /*
                Even index -> expected '0'
                Odd index  -> expected '1'
            */
            if ((index % 2 == 0 && s.charAt(index) == '1') ||
                (index % 2 == 1 && s.charAt(index) == '0')) {

                flipsStartingWithZero++;
            }
        }

        /*
            If pattern starts with '1':
            flips = remaining mismatches
        */
        int flipsStartingWithOne = stringLength - flipsStartingWithZero;

        // Return minimum flips
        return Math.min(flipsStartingWithZero, flipsStartingWithOne);
    }
}
