// Solution for Number of Ways to Divide a Long Corridor in JAVA

class Solution {
    public int numberOfWays(String corridor) {
        final int MOD = 1_000_000_007;
        int n = corridor.length();

        // STEP 1: Collect indices of all seats ('S')
        List<Integer> seatIndices = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (corridor.charAt(i) == 'S') {
                seatIndices.add(i);
            }
        }

        // STEP 2: Validate seat count
        int totalSeats = seatIndices.size();
        if (totalSeats == 0 || totalSeats % 2 != 0) {
            return 0;
        }

        // STEP 3: Calculate number of ways
        long ways = 1;

        // Second seat of the first section
        int previousSectionEnd = seatIndices.get(1);

        // Process each new section
        for (int i = 2; i < totalSeats; i += 2) {

            // Divider choices between sections
            int dividerChoices = seatIndices.get(i) - previousSectionEnd;

            ways = (ways * dividerChoices) % MOD;

            // Update end of current section
            previousSectionEnd = seatIndices.get(i + 1);
        }

        return (int) ways;
    }
}
