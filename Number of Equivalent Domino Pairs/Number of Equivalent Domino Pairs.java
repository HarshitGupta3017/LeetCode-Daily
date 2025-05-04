// Solution for Number of Equivalent Domino Pairs in JAVA

class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        Map<Integer, Integer> mp = new HashMap<>();
        int res = 0;
        for (int[] d: dominoes) {
            int key = Math.min(d[0], d[1]) * 10 + Math.max(d[0], d[1]);
            res += mp.getOrDefault(key, 0);
            mp.put(key, mp.getOrDefault(key, 0) + 1);
        }
        return res; 
    }
}
