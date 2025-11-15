// Solution for Count the Number of Substrings With Dominant Ones in JAVA

class Solution {
    public int numberOfSubstrings(String s) {

        int n = s.length();
        int result = 0;

        // 🔹 Prefix array storing cumulative count of '1's
        int[] prefixOnes = new int[n];
        prefixOnes[0] = (s.charAt(0) == '1') ? 1 : 0;

        for (int i = 1; i < n; i++) {
            prefixOnes[i] = prefixOnes[i - 1] + (s.charAt(i) == '1' ? 1 : 0);
        }

        // 🔹 Traverse all substrings via left and right pointers
        for (int left = 0; left < n; left++) {

            for (int right = left; right < n; right++) {

                // Count ones in substring s[left...right]
                int ones = prefixOnes[right] - (left > 0 ? prefixOnes[left - 1] : 0);

                // Count zeros
                int zeroes = (right - left + 1) - ones;

                // Case A: Not dominant → ones < zeroes², SKIP ahead
                if (zeroes * zeroes > ones) {
                    int neededOnes = (zeroes * zeroes) - ones;
                    right += neededOnes - 1;
                }

                // Case B: exact match
                else if (zeroes * zeroes == ones) {
                    result++;
                }

                // Case C: dominant
                else {
                    result++;

                    int jump = (int)Math.sqrt(ones) - zeroes;

                    int nextRight = right + jump;

                    if (nextRight >= n) {
                        result += (n - right - 1);
                        break;
                    }

                    result += jump;
                    right = nextRight;
                }
            }
        }

        return result;
    }
}
