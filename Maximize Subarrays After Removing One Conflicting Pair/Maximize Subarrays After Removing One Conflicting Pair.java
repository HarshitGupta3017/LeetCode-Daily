// Solution for Maximize Subarrays After Removing One Conflicting Pair in JAVA

class Solution {
    public long maxSubarrays(int n, int[][] conflictingPairs) {
        List<List<Integer>> conflictWithLeft = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            conflictWithLeft.add(new ArrayList<>());
        }

        for (int[] pair : conflictingPairs) {
            int a = pair[0];
            int b = pair[1];
            int larger = Math.max(a, b);
            int smaller = Math.min(a, b);
            conflictWithLeft.get(larger).add(smaller);
        }

        int maxLeft = 0;
        int secondMaxLeft = 0;
        long validSubarrays = 0;
        long[] extraGain = new long[n + 1];

        for (int end = 1; end <= n; end++) {
            for (int leftConflict : conflictWithLeft.get(end)) {
                if (leftConflict >= maxLeft) {
                    secondMaxLeft = maxLeft;
                    maxLeft = leftConflict;
                } else if (leftConflict > secondMaxLeft) {
                    secondMaxLeft = leftConflict;
                }
            }

            validSubarrays += (end - maxLeft);
            extraGain[maxLeft] += (maxLeft - secondMaxLeft);
        }

        long maxExtra = 0;
        for (long gain : extraGain) {
            maxExtra = Math.max(maxExtra, gain);
        }

        return validSubarrays + maxExtra;
    }
}
