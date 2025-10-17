// Solution for Maximize the Number of Partitions After Operations in JAVA

class Solution {
    private static final int ALPHABET_SIZE = 26;

    private int solve(int index, int mask, boolean canModify, String s, int k, Map<Long, Integer> memo) {
        long key = (((long) index) << 27) | (((long) mask) << 1) | (canModify ? 1 : 0);
        if (memo.containsKey(key)) return memo.get(key);
        if (index >= s.length()) return 0;

        int chBit = s.charAt(index) - 'a';
        int newMask = mask | (1 << chBit);
        int unique = Integer.bitCount(newMask);

        int maxParts;
        if (unique > k)
            maxParts = 1 + solve(index + 1, (1 << chBit), canModify, s, k, memo);
        else
            maxParts = solve(index + 1, newMask, canModify, s, k, memo);

        if (canModify) {
            for (int rep = 0; rep < ALPHABET_SIZE; rep++) {
                int modMask = mask | (1 << rep);
                int modUnique = Integer.bitCount(modMask);
                if (modUnique > k)
                    maxParts = Math.max(maxParts, 1 + solve(index + 1, (1 << rep), false, s, k, memo));
                else
                    maxParts = Math.max(maxParts, solve(index + 1, modMask, false, s, k, memo));
            }
        }

        memo.put(key, maxParts);
        return maxParts;
    }

    public int maxPartitionsAfterOperations(String s, int k) {
        return solve(0, 0, true, s, k, new HashMap<>()) + 1;
    }
}
