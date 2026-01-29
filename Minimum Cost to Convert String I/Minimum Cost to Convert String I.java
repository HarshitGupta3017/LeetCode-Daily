// Solution for Minimum Cost to Convert String I in JAVA

class Solution {

    /*
        This function builds the graph and applies Floyd–Warshall
        to compute the minimum cost to convert any character
        ('a' to 'z') into any other character.
    */
    private void floydWarshall(
        long[][] minCostMatrix,
        char[] originalChars,
        char[] changedChars,
        int[] transformationCosts
    ) {
        // Step 1: Initialize direct transformation costs
        // For each allowed transformation original -> changed,
        // keep the minimum cost (there may be duplicate rules).
        for (int i = 0; i < originalChars.length; i++) {
            int fromChar = originalChars[i] - 'a';
            int toChar   = changedChars[i] - 'a';

            minCostMatrix[fromChar][toChar] =
                Math.min(minCostMatrix[fromChar][toChar],
                         transformationCosts[i]);
        }

        // Step 2: Floyd–Warshall algorithm
        // Try using every character as an intermediate node
        // to minimize the cost between all pairs of characters.
        for (int intermediate = 0; intermediate < 26; intermediate++) {
            for (int from = 0; from < 26; from++) {
                for (int to = 0; to < 26; to++) {
                    // Relax the path: from -> intermediate -> to
                    minCostMatrix[from][to] = Math.min(
                        minCostMatrix[from][to],
                        minCostMatrix[from][intermediate] +
                        minCostMatrix[intermediate][to]
                    );
                }
            }
        }
    }

    /*
        Main function:
        Computes the minimum total cost to convert `source` into `target`.
        Returns -1 if any character conversion is impossible.
    */
    public long minimumCost(
        String source,
        String target,
        char[] original,
        char[] changed,
        int[] cost
    ) {
        // minCostMatrix[i][j] = minimum cost to convert
        // character (i + 'a') into (j + 'a')
        long[][] minCostMatrix = new long[26][26];

        // Initialize all costs as "infinite"
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                minCostMatrix[i][j] = Long.MAX_VALUE / 2; 
                // divide by 2 to prevent overflow during addition
            }
        }

        // Compute all-pairs minimum transformation costs
        floydWarshall(minCostMatrix, original, changed, cost);

        long totalCost = 0;

        // Compare each character of source and target
        for (int i = 0; i < source.length(); i++) {
            int sourceChar = source.charAt(i) - 'a';
            int targetChar = target.charAt(i) - 'a';

            // If characters are already the same, no cost needed
            if (sourceChar == targetChar) {
                continue;
            }

            // If conversion is impossible, return -1
            if (minCostMatrix[sourceChar][targetChar] >= Long.MAX_VALUE / 2) {
                return -1;
            }

            // Add the minimum cost for this character conversion
            totalCost += minCostMatrix[sourceChar][targetChar];
        }

        return totalCost;
    }
}
