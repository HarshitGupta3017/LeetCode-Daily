// Solution for Rabbits in Forest in JAVA

class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> count = new HashMap<>();
        int result = 0;
        for (int ans : answers) {
            count.put(ans, count.getOrDefault(ans, 0) + 1);
        }
        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            int k = entry.getKey();
            int freq = entry.getValue();
            int groupSize = k + 1;
            int groups = (int) Math.ceil((double) freq / groupSize);
            result += groups * groupSize;
        }
        return result;
    }
}
