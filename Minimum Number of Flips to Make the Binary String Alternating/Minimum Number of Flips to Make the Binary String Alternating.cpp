// Solution for Minimum Number of Flips to Make the Binary String Alternating in CPP

class Solution {
public:
    int minFlips(string s) {

        int n = s.size();

        /*
            Result stores the minimum number of flips
            required among all rotations.
        */
        int minimumFlips = INT_MAX;

        /*
            flipsPattern0:
            flips needed if the pattern starts with '0'

            Pattern:
            0 1 0 1 0 1 ...
        */
        int flipsPattern0 = 0;

        /*
            Sliding window pointers
        */
        int left = 0;

        /*
            We simulate rotations by iterating over
            the string twice (s + s).
        */
        for (int right = 0; right < 2 * n; right++) {

            /*
                Expected character for pattern starting with '0'
            */
            char expectedChar = (right % 2) ? '1' : '0';

            /*
                If the current character does not match the
                expected alternating pattern, we must flip it.
            */
            if (s[right % n] != expectedChar) {
                flipsPattern0++;
            }

            /*
                If window size becomes larger than n,
                remove the effect of the leftmost element.
            */
            if (right - left + 1 > n) {

                char expectedLeft = (left % 2) ? '1' : '0';

                if (s[left % n] != expectedLeft) {
                    flipsPattern0--;
                }

                left++;
            }

            /*
                Once window size equals n,
                we have a valid rotation to evaluate.
            */
            if (right - left + 1 == n) {

                /*
                    flipsPattern1 corresponds to pattern:
                    1 0 1 0 1 0 ...
                */
                int flipsPattern1 = n - flipsPattern0;

                minimumFlips = min({minimumFlips, flipsPattern0, flipsPattern1});
            }
        }

        return minimumFlips;
    }
};
