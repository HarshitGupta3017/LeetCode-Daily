// Solution for Maximum Total Damage With Spell Casting in JAVA

import java.util.*;

class Solution {
    // Recursive helper function to compute maximum total damage
    private long computeMaxDamage(List<Long> uniqueDamages, int i, long[] memo, Map<Integer, Long> damageCountMap) {
        // Base case: no more spells
        if (i >= uniqueDamages.size()) return 0;

        // If already computed, return memoized value
        if (memo[i] != -1) return memo[i];

        // Option 1: Skip current spell
        long skipCurrent = computeMaxDamage(uniqueDamages, i + 1, memo, damageCountMap);

        // Option 2: Take current spell damage and skip incompatible ones
        long currentDamage = uniqueDamages.get(i);
        long nextValidDamage = currentDamage + 3;

        // Binary search for next valid index (similar to upper_bound in C++)
        int nextIndex = Collections.binarySearch(uniqueDamages, nextValidDamage + 0L);
        if (nextIndex < 0) nextIndex = -(nextIndex + 1);

        long takeCurrent = currentDamage * damageCountMap.get((int) currentDamage)
                + computeMaxDamage(uniqueDamages, nextIndex, memo, damageCountMap);

        // Store and return the maximum of both options
        return memo[i] = Math.max(skipCurrent, takeCurrent);
    }

    public long maximumTotalDamage(int[] power) {
        Map<Integer, Long> damageCountMap = new HashMap<>();

        // Count frequency of each unique damage value
        for (int damage : power) {
            damageCountMap.put(damage, damageCountMap.getOrDefault(damage, 0L) + 1);
        }

        // Extract unique damage values and sort them
        List<Long> uniqueDamages = new ArrayList<>();
        for (int dmg : damageCountMap.keySet()) {
            uniqueDamages.add((long) dmg);
        }
        Collections.sort(uniqueDamages);

        int n = uniqueDamages.size();
        long[] memo = new long[n];
        Arrays.fill(memo, -1);

        // Compute and return the maximum possible total damage
        return computeMaxDamage(uniqueDamages, 0, memo, damageCountMap);
    }
}
