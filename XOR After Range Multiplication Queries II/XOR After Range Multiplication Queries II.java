// Solution for XOR After Range Multiplication Queries II in JAVA

class Solution {

    static final long MOD = 1_000_000_007;

    // Fast exponentiation (binary exponentiation)
    long power(long base, long exponent) {
        if (exponent == 0) return 1;

        long half = power(base, exponent / 2);
        long result = (half * half) % MOD;

        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        return result;
    }

    public int xorAfterQueries(int[] nums, int[][] queries) {

        int n = nums.length;
        int blockSize = (int) Math.ceil(Math.sqrt(n));

        Map<Integer, List<int[]>> smallKQueries = new HashMap<>();

        // STEP 1: Process large K directly
        for (int[] query : queries) {
            int left = query[0];
            int right = query[1];
            int step = query[2];
            int multiplier = query[3];

            if (step >= blockSize) {
                for (int i = left; i <= right; i += step) {
                    nums[i] = (int)((nums[i] * 1L * multiplier) % MOD);
                }
            } else {
                smallKQueries.computeIfAbsent(step, k -> new ArrayList<>()).add(query);
            }
        }

        // STEP 2: Process small K
        for (int step : smallKQueries.keySet()) {
            List<int[]> list = smallKQueries.get(step);

            long[] diff = new long[n];
            Arrays.fill(diff, 1);

            for (int[] query : list) {
                int left = query[0];
                int right = query[1];
                int multiplier = query[3];

                diff[left] = (diff[left] * multiplier) % MOD;

                int stepsCount = (right - left) / step;
                int nextIndex = left + (stepsCount + 1) * step;

                if (nextIndex < n) {
                    long inv = power(multiplier, MOD - 2);
                    diff[nextIndex] = (diff[nextIndex] * inv) % MOD;
                }
            }

            for (int i = 0; i < n; i++) {
                if (i - step >= 0) {
                    diff[i] = (diff[i] * diff[i - step]) % MOD;
                }
            }

            for (int i = 0; i < n; i++) {
                nums[i] = (int)((nums[i] * diff[i]) % MOD);
            }
        }

        // STEP 3: XOR result
        int finalXOR = 0;
        for (int num : nums) {
            finalXOR ^= num;
        }

        return finalXOR;
    }
}
