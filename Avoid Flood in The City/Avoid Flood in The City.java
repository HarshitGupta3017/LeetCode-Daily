// Solution for Avoid Flood in The City in JAVA

class Solution {
    public int[] avoidFlood(int[] rains) {
        int n = rains.length;
        Map<Integer, Integer> lastRainDay = new HashMap<>(); // lake -> last day it rained
        TreeSet<Integer> dryDays = new TreeSet<>();          // indices of dry days
        int[] result = new int[n];

        // Initialize dry day default values as 1
        Arrays.fill(result, 1);

        for (int day = 0; day < n; day++) {
            int lake = rains[day];
            if (lake == 0) {
                dryDays.add(day); // Dry day, can be used later
            } else {
                result[day] = -1; // Rain day must be -1

                if (lastRainDay.containsKey(lake)) {
                    // Find the next available dry day after last rain
                    Integer dryDay = dryDays.ceiling(lastRainDay.get(lake));
                    if (dryDay == null) {
                        // No dry day available → flood
                        return new int[0];
                    }
                    result[dryDay] = lake; // Dry this lake on that day
                    dryDays.remove(dryDay);
                }

                // Update last day this lake was filled
                lastRainDay.put(lake, day);
            }
        }

        return result;
    }
}
