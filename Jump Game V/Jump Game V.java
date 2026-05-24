// Solution for Jump Game V in JAVA

class Solution {
    public int maxJumps(int[] arr, int d) {

        int totalElements = arr.length;

        // dp[i] stores maximum indices that can be visited
        // starting from index i
        int[] dp = new int[totalElements];
        Arrays.fill(dp, 1);

        // Store {value, index} pairs
        // to process smaller elements first
        List<int[]> sortedElements = new ArrayList<>();

        for (int index = 0; index < totalElements; index++) {
            sortedElements.add(new int[]{arr[index], index});
        }

        sortedElements.sort(Comparator.comparingInt(a -> a[0]));

        // Process indices in increasing order of values
        for (int[] element : sortedElements) {

            int currentIndex = element[1];

            int bestReach = 1;

            // Explore left side within jump distance
            for (int nextIndex = currentIndex - 1;
                 nextIndex >= Math.max(0, currentIndex - d);
                 nextIndex--) {

                // Cannot jump across equal or larger element
                if (arr[nextIndex] >= arr[currentIndex]) {
                    break;
                }

                bestReach = Math.max(bestReach, 1 + dp[nextIndex]);
            }

            // Explore right side within jump distance
            for (int nextIndex = currentIndex + 1;
                 nextIndex <= Math.min(totalElements - 1, currentIndex + d);
                 nextIndex++) {

                // Cannot jump across equal or larger element
                if (arr[nextIndex] >= arr[currentIndex]) {
                    break;
                }

                bestReach = Math.max(bestReach, 1 + dp[nextIndex]);
            }

            dp[currentIndex] = bestReach;
        }

        // Maximum reachable indices from any starting point
        int answer = 1;

        for (int value : dp) {
            answer = Math.max(answer, value);
        }

        return answer;
    }
}
