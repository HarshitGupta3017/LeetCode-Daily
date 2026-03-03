// Solution for Find Kth Bit in Nth Binary String in CPP

class Solution {
public:
    char findKthBit(int n, int k) {

        /*
            Base Case:
            S1 = "0"
            So the only bit is '0'
        */
        if (n == 1) {
            return '0';
        }

        /*
            Length of Sn = 2^n - 1
            Middle index = 2^(n-1)
        */
        int lengthOfCurrentString = (1 << n) - 1;
        int middleIndex = 1 << (n - 1);

        /*
            Case 1:
            If k is exactly at middle,
            that position is always '1'
        */
        if (k == middleIndex) {
            return '1';
        }

        /*
            Case 2:
            If k lies in the LEFT half,
            it is exactly same as kth bit of Sn-1.
        */
        if (k < middleIndex) {
            return findKthBit(n - 1, k);
        }

        /*
            Case 3:
            k lies in RIGHT half.

            Right half = reverse(invert(Sn-1))

            Because of reverse,
            we find the mirrored position
            in the left half:

            mirrorIndex = length - k + 1
        */
        int mirrorIndex = lengthOfCurrentString - k + 1;

        /*
            Recursively find that mirrored bit
            from Sn-1.
        */
        char mirroredBit = findKthBit(n - 1, mirrorIndex);

        /*
            Since right half is inverted,
            we flip the bit before returning.
        */
        return (mirroredBit == '0') ? '1' : '0';
    }
};
