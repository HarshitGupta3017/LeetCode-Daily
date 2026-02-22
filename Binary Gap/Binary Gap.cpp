// Solution for Binary Gap in CPP

class Solution {
public:
    int binaryGap(int n) {

        /*
            prevPosition:
            stores the bit index of the previous '1'
            initialize with -1 (means none seen yet)
        */
        int prevPosition = -1;

        /*
            maxDistance:
            stores the maximum gap found so far
        */
        int maxDistance = 0;

        /*
            A 32-bit integer has at most 32 bits.
            We check each bit position from 0 to 31.
        */
        for (int currentPosition = 0; currentPosition < 32; currentPosition++) {

            /*
                Extract the bit at currentPosition.

                (n >> currentPosition) shifts the bit to LSB.
                & 1 isolates that bit.
            */
            if ((n >> currentPosition) & 1) {

                /*
                    If we have seen a '1' before,
                    calculate the distance between
                    current and previous positions.
                */
                if (prevPosition != -1) {
                    int distance = currentPosition - prevPosition;
                    maxDistance = max(maxDistance, distance);
                }

                /*
                    Update prevPosition
                    to the current bit index.
                */
                prevPosition = currentPosition;
            }
        }

        return maxDistance;
    }
};
