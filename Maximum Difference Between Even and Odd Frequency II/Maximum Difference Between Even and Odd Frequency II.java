// Solution for Maximum Difference Between Even and Odd Frequency II in JAVA

class Solution {
    
    int getState(int countA, int countB) {
        int parityA = countA % 2;
        int parityB = countB % 2;
        if (parityA == 0 && parityB == 0) return 0;
        if (parityA == 0 && parityB == 1) return 1;
        if (parityA == 1 && parityB == 0) return 2;
        return 3;
        // return (parityA << 1) | parityB;
    }

    public int maxDifference(String s, int k) {
        int n = s.length();
        int maxDiff = Integer.MIN_VALUE;

        for (char a = '0'; a <= '4'; a++) {
            for (char b = '0'; b <= '4'; b++) {
                if (a == b) continue;

                int[] minPrefixDiffForState = new int[4];
                Arrays.fill(minPrefixDiffForState, Integer.MAX_VALUE);

                int totalCountA = 0, totalCountB = 0;
                int leftCountA = 0, leftCountB = 0;
                int left = -1, right = 0;

                while (right < n) {
                    if (s.charAt(right) == a) totalCountA++;
                    if (s.charAt(right) == b) totalCountB++;

                    while (right - left >= k && totalCountB - leftCountB >= 2 && totalCountA - leftCountA >= 1) {
                        int leftState = getState(leftCountA, leftCountB);
                        minPrefixDiffForState[leftState] = Math.min(
                            minPrefixDiffForState[leftState],
                            leftCountA - leftCountB
                        );

                        left++;
                        if (left < n) {
                            if (s.charAt(left) == a) leftCountA++;
                            if (s.charAt(left) == b) leftCountB++;
                        }
                    }

                    int currentState = getState(totalCountA, totalCountB);
                    int requiredPrevState = currentState ^ 2;

                    if (minPrefixDiffForState[requiredPrevState] != Integer.MAX_VALUE) {
                        int diff = (totalCountA - totalCountB) - minPrefixDiffForState[requiredPrevState];
                        maxDiff = Math.max(maxDiff, diff);
                    }

                    right++;
                }
            }
        }

        return maxDiff;
    }
}
