// Solution for Maximum Candies You Can Get from Boxes in JAVA

class Solution {

    private int dfs(
        int box,
        int[] status,
        int[] candies,
        int[][] keys,
        int[][] containedBoxes,
        boolean[] visited,
        Set<Integer> foundBoxes
    ) {
        // If we've already visited this box, skip it
        if (visited[box]) return 0;

        // If the box is locked, save it for future when we get its key
        if (status[box] == 0) {
            foundBoxes.add(box);
            return 0;
        }

        // Mark the box as visited
        visited[box] = true;
        int collectedCandies = candies[box];  // Collect candies in current box

        // Recursively explore boxes found inside the current box
        for (int innerBox : containedBoxes[box]) {
            collectedCandies += dfs(innerBox, status, candies, keys, containedBoxes, visited, foundBoxes);
        }

        // Use keys found in the current box
        for (int unlockBox : keys[box]) {
            status[unlockBox] = 1;  // Mark the box as open
            // If we already found this box before (but it was locked), explore it now
            if (foundBoxes.contains(unlockBox)) {
                collectedCandies += dfs(unlockBox, status, candies, keys, containedBoxes, visited, foundBoxes);
            }
        }

        return collectedCandies;
    }

    public int maxCandies(
        int[] status,
        int[] candies,
        int[][] keys,
        int[][] containedBoxes,
        int[] initialBoxes
    ) {
        int n = candies.length;
        int totalCandies = 0;

        boolean[] visited = new boolean[n];     // To avoid visiting the same box again
        Set<Integer> foundBoxes = new HashSet<>();  // Boxes found but not yet openable

        // Start DFS from each initially available box
        for (int box : initialBoxes) {
            totalCandies += dfs(box, status, candies, keys, containedBoxes, visited, foundBoxes);
        }

        return totalCandies;
    }
}
