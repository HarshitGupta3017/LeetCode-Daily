// Solution for Count the Number of Substrings With Dominant Ones in CPP

class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();
        int result = 0;

        // 🔹 Prefix array storing total count of '1's up to each index.
        //    prefixOnes[i] = number of ones in s[0...i]
        vector<int> prefixOnes(n, 0);
        prefixOnes[0] = (s[0] == '1') ? 1 : 0;

        // Build prefix sum for ones
        for (int i = 1; i < n; i++) {
            prefixOnes[i] = prefixOnes[i - 1] + (s[i] == '1');
        }

        // 🔹 Try every substring starting index
        for (int left = 0; left < n; left++) {

            // 🔹 Expand right pointer and process substrings s[left...right]
            for (int right = left; right < n; right++) {

                // Count ones in substring s[left...right]
                int ones = prefixOnes[right] -
                           (left > 0 ? prefixOnes[left - 1] : 0);

                // Count zeroes = total length - ones
                int zeroes = (right - left + 1) - ones;

                // Case A: #ones < (#zeroes²) → Not dominant
                // Instead of moving right one-by-one, we SKIP ahead
                if (zeroes * zeroes > ones) {

                    // How many ones needed to satisfy: ones >= zeroes²
                    int neededOnes = (zeroes * zeroes) - ones;

                    // Moving `right` ahead by neededOnes - 1 saves time
                    right += neededOnes - 1;
                }

                // Case B: #ones == (#zeroes²) → Dominant, count it
                else if (zeroes * zeroes == ones) {
                    result += 1;
                }

                // Case C: #ones > (#zeroes²) → Dominant
                else {

                    // This substring is dominant
                    result += 1;

                    // We try to jump ahead further:
                    // Let zeroes² < ones
                    // zeroes < sqrt(ones)
                    // zeroes + k < sqrt(ones) for as many k as possible
                    int jump = sqrt(ones) - zeroes;

                    // Compute the next position we're allowed to jump to
                    int nextRight = right + jump;

                    // If nextRight goes outside bounds → count all remaining substrings
                    if (nextRight >= n) {
                        result += (n - right - 1); // all substrings ending beyond right
                        break;
                    }

                    // Otherwise we gain +jump more dominant substrings
                    result += jump;

                    // Jump right pointer to skip useless checks
                    right = nextRight;
                }
            }
        }

        return result;
    }
};
