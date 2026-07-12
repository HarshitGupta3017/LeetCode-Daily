// Solution for Rank Transform of an Array in JAVA

class Solution {
    public int[] arrayRankTransform(int[] arr) {
        // Work on a sorted copy so the original order is preserved.
        int[] sorted = arr.clone();
        Arrays.sort(sorted);

        // Map each unique value to its rank.
        Map<Integer, Integer> rankOf = new HashMap<>();
        int nextRank = 1;

        for (int num : sorted) {
            if (!rankOf.containsKey(num)) {
                rankOf.put(num, nextRank++);
            }
        }

        // Replace each original element with its rank.
        int[] result = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            result[i] = rankOf.get(arr[i]);
        }

        return result;
    }
}
