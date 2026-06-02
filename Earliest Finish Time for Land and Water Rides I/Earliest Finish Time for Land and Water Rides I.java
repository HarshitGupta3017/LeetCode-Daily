// Solution for Earliest Finish Time for Land and Water Rides I in JAVA

class Solution {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration,
                                  int[] waterStartTime, int[] waterDuration) {
        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < landStartTime.length; i++) {
            int landEnd = landStartTime[i] + landDuration[i];

            for (int j = 0; j < waterStartTime.length; j++) {
                int waterEnd = waterStartTime[j] + waterDuration[j];

                int landWater = Math.max(landEnd, waterStartTime[j]) + waterDuration[j];
                int waterLand = Math.max(waterEnd, landStartTime[i]) + landDuration[i];

                ans = Math.min(ans, Math.min(landWater, waterLand));
            }
        }
        return ans;
    }
}
