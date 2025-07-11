// Solution for Meeting Rooms III in JAVA

class Solution {
    public int mostBooked(int n, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));
        long[] roomFreeTime = new long[n];
        int[] roomUsage = new int[n];

        for (int[] meeting : meetings) {
            int start = meeting[0], end = meeting[1], duration = end - start;
            boolean assigned = false;
            long earliest = Long.MAX_VALUE;
            int earliestRoom = 0;

            for (int i = 0; i < n; i++) {
                if (roomFreeTime[i] <= start) {
                    roomFreeTime[i] = end;
                    roomUsage[i]++;
                    assigned = true;
                    break;
                }
                if (roomFreeTime[i] < earliest) {
                    earliest = roomFreeTime[i];
                    earliestRoom = i;
                }
            }

            if (!assigned) {
                roomFreeTime[earliestRoom] += duration;
                roomUsage[earliestRoom]++;
            }
        }

        int maxRoom = 0;
        for (int i = 1; i < n; i++) {
            if (roomUsage[i] > roomUsage[maxRoom]) {
                maxRoom = i;
            }
        }
        return maxRoom;
    }
}
