// Solution for Cinema Seat Allocation in JAVA

class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {

        // Encode each row's reserved seats as a bitmask.
        Map<Integer, Integer> reservedMask = new HashMap<>();

        for (int[] rs : reservedSeats) {
            int row = rs[0];
            int seat = rs[1];

            reservedMask.put(row,
                reservedMask.getOrDefault(row, 0) | (1 << seat));
        }

        // Rows with no reservations can fit two groups.
        int totalGroups = (n - reservedMask.size()) * 2;

        // Block A: seats 2-5
        // Block B: seats 4-7
        // Block C: seats 6-9
        int blockA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int blockB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int blockC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (int mask : reservedMask.values()) {

            boolean fitsA = (mask & blockA) == 0;
            boolean fitsB = (mask & blockB) == 0;
            boolean fitsC = (mask & blockC) == 0;

            if (fitsA && fitsC) {
                totalGroups += 2;
            } else if (fitsA || fitsB || fitsC) {
                totalGroups += 1;
            }
        }

        return totalGroups;
    }
}
