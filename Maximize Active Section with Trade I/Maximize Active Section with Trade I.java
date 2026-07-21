// Solution for Maximize Active Section with Trade I in JAVA

class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        int n = s.length();

        // Count total active sections ('1')
        int totalActive = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') totalActive++;
        }

        // Store lengths of contiguous 0-blocks
        List<Integer> zeroBlockLengths = new ArrayList<>();
        int i = 0;
        while (i < n) {
            if (s.charAt(i) == '0') {
                int start = i;
                while (i < n && s.charAt(i) == '0') {
                    i++;
                }
                zeroBlockLengths.add(i - start);
            } else {
                i++;
            }
        }

        // Find maximum sum of adjacent 0-block lengths
        int maxGain = 0;
        for (int j = 1; j < zeroBlockLengths.size(); j++) {
            maxGain = Math.max(maxGain,
                    zeroBlockLengths.get(j) + zeroBlockLengths.get(j - 1));
        }

        return totalActive + maxGain;
    }
}
