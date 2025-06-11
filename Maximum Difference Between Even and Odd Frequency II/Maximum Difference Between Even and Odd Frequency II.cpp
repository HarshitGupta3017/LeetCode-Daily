// Solution for Maximum Difference Between Even and Odd Frequency II in CPP

class Solution {
public:

    // Determine the parity state of counts: 
    // 0 = even-even, 1 = even-odd, 2 = odd-even, 3 = odd-odd
    int getState(int countA, int countB) {
        int parityA = countA % 2;
        int parityB = countB % 2;
        if (parityA == 0 && parityB == 0) return 0; // even even (00)
        if (parityA == 0 && parityB == 1) return 1; // even odd (01)
        if (parityA == 1 && parityB == 0) return 2; // odd even (10)
        return 3; // odd odd (11)
        // return (parityA << 1) | parityB; // combine parity bits
    }

    int maxDifference(string s, int k) {
        int n = s.length();
        int maxDiff = INT_MIN;

        // Try all pairs of characters a and b ('0' to '4'), where a != b
        for (char a = '0'; a <= '4'; a++) {
            for (char b = '0'; b <= '4'; b++) {
                if (a == b) continue;

                // Stores the minimum value of (countA - countB) for each state
                vector<int> minPrefixDiffForState(4, INT_MAX);

                // Total counts of a and b up to the current index
                int totalCountA = 0, totalCountB = 0;

                // Counts of a and b from left index
                int leftCountA = 0, leftCountB = 0;

                int left = -1, right = 0;

                while (right < n) {
                    // Update counts with current character
                    totalCountA += (s[right] == a);
                    totalCountB += (s[right] == b);

                    // Shrink window from left while maintaining minimum required length
                    while (right - left >= k && totalCountB - leftCountB >= 2 && totalCountA - leftCountA >= 1) {
                        int leftState = getState(leftCountA, leftCountB);
                        minPrefixDiffForState[leftState] = min(minPrefixDiffForState[leftState], leftCountA - leftCountB);

                        // Move left pointer and update counts
                        left++;
                        leftCountA += (s[left] == a);
                        leftCountB += (s[left] == b);
                    }

                    // Current window state
                    int currentState = getState(totalCountA, totalCountB);

                    // Find corresponding previous state with a=odd, b=even (using XOR with 2 flips parity of a)
                    int requiredPrevState = currentState ^ 2;

                    if (minPrefixDiffForState[requiredPrevState] != INT_MAX) {
                        int diff = (totalCountA - totalCountB) - minPrefixDiffForState[requiredPrevState];
                        maxDiff = max(maxDiff, diff);
                    }

                    right++;
                }
            }
        }

        return maxDiff;
    }
};
