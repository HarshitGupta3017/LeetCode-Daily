// Solution for Minimum Number of Flips to Make the Binary String Alternating in JAVA

class Solution {
    public int minFlips(String s) {

        int n = s.length();
        int minimumFlips = Integer.MAX_VALUE;

        int flipsPattern0 = 0;
        int left = 0;

        for (int right = 0; right < 2 * n; right++) {

            char expectedChar = (right % 2 == 1) ? '1' : '0';

            if (s.charAt(right % n) != expectedChar) {
                flipsPattern0++;
            }

            // shrink window if > n
            if (right - left + 1 > n) {

                char expectedLeft = (left % 2 == 1) ? '1' : '0';

                if (s.charAt(left % n) != expectedLeft) {
                    flipsPattern0--;
                }

                left++;
            }

            // evaluate window
            if (right - left + 1 == n) {

                int flipsPattern1 = n - flipsPattern0;

                minimumFlips = Math.min(
                        minimumFlips,
                        Math.min(flipsPattern0, flipsPattern1)
                );
            }
        }

        return minimumFlips;
    }
}
