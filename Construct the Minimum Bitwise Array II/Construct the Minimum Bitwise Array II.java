// Solution for Construct the Minimum Bitwise Array II in JAVA

class Solution {

    public int[] minBitwiseArray(List<Integer> nums) {

        int n = nums.size();
        int[] answer = new int[n];

        for (int idx = 0; idx < n; idx++) {

            int target = nums.get(idx);

            /*
                Special case:
                2 (binary: 10) cannot be formed because
                no x exists such that x | (x + 1) = 2
            */
            if (target == 2) {
                answer[idx] = -1;
                continue;
            }

            boolean foundValid = false;

            /*
                Find the first zero bit in target
            */
            for (int bit = 1; bit < 32; bit++) {

                // If this bit is already set, skip
                if ((target & (1 << bit)) != 0) continue;

                /*
                    Flip the previous bit to simulate
                    carry behavior of (x + 1)
                */
                int candidate = target ^ (1 << (bit - 1));

                answer[idx] = candidate;
                foundValid = true;
                break;
            }

            // If no valid x exists
            if (!foundValid) {
                answer[idx] = -1;
            }
        }

        return answer;
    }
}
