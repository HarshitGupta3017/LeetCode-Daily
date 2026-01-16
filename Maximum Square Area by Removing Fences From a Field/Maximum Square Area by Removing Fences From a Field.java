// Solution for Maximum Square Area by Removing Fences From a Field in JAVA

class Solution {
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {

        final int MOD = 1_000_000_007;

        // Convert arrays to lists so we can add boundary fences
        List<Integer> horizontalFences = new ArrayList<>();
        List<Integer> verticalFences = new ArrayList<>();

        for (int fence : hFences) horizontalFences.add(fence);
        for (int fence : vFences) verticalFences.add(fence);

        // Add boundary fences (cannot be removed)
        horizontalFences.add(1);
        horizontalFences.add(m);
        verticalFences.add(1);
        verticalFences.add(n);

        // Sort fence positions
        Collections.sort(horizontalFences);
        Collections.sort(verticalFences);

        /*
            Store all possible heights formed
            by choosing any two horizontal fences
        */
        Set<Integer> possibleHeights = new HashSet<>();
        int horizontalCount = horizontalFences.size();

        for (int i = 0; i < horizontalCount; i++) {
            for (int j = i + 1; j < horizontalCount; j++) {
                possibleHeights.add(
                    horizontalFences.get(j) - horizontalFences.get(i)
                );
            }
        }

        /*
            Check vertical distances and
            find the largest common distance
        */
        int maxSquareSide = 0;
        int verticalCount = verticalFences.size();

        for (int i = 0; i < verticalCount; i++) {
            for (int j = i + 1; j < verticalCount; j++) {
                int width = verticalFences.get(j) - verticalFences.get(i);
                if (possibleHeights.contains(width)) {
                    maxSquareSide = Math.max(maxSquareSide, width);
                }
            }
        }

        // If no square possible
        if (maxSquareSide == 0) return -1;

        long area = (long) maxSquareSide * maxSquareSide;
        return (int) (area % MOD);
    }
}
