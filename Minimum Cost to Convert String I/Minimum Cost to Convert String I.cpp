// Solution for Minimum Cost to Convert String I in CPP

class Solution {
public:
    using ll = long long;

    /*
        This function builds the graph and applies Floyd–Warshall
        to compute the minimum cost to convert any character
        ('a' to 'z') into any other character.
    */
    void floydWarshall(
        vector<vector<ll>>& minCostMatrix,
        vector<char>& originalChars,
        vector<char>& changedChars,
        vector<int>& transformationCosts
    ) {
        // Step 1: Initialize direct transformation costs
        // For each allowed transformation original -> changed,
        // keep the minimum cost (there may be duplicates).
        for (int i = 0; i < originalChars.size(); i++) {
            int fromChar = originalChars[i] - 'a';
            int toChar   = changedChars[i] - 'a';

            minCostMatrix[fromChar][toChar] =
                min(minCostMatrix[fromChar][toChar],
                    (ll)transformationCosts[i]);
        }

        // Step 2: Floyd–Warshall algorithm
        // Try using every character as an intermediate node
        // to minimize the cost between all pairs of characters.
        for (int intermediate = 0; intermediate < 26; intermediate++) {
            for (int from = 0; from < 26; from++) {
                for (int to = 0; to < 26; to++) {
                    // If going from -> intermediate -> to is cheaper,
                    // update the minimum cost.
                    minCostMatrix[from][to] = min(
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
    long long minimumCost(
        string source,
        string target,
        vector<char>& original,
        vector<char>& changed,
        vector<int>& cost
    ) {
        // minCostMatrix[i][j] = minimum cost to convert
        // character (i + 'a') into (j + 'a')
        vector<vector<ll>> minCostMatrix(
            26, vector<ll>(26, INT_MAX)
        );

        // Run Floyd–Warshall to compute all-pairs minimum costs
        floydWarshall(minCostMatrix, original, changed, cost);

        ll totalCost = 0;

        // Compare each character of source and target
        for (int i = 0; i < source.size(); i++) {
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';

            // If characters are already equal, no cost needed
            if (sourceChar == targetChar) {
                continue;
            }

            // If conversion is impossible, return -1
            if (minCostMatrix[sourceChar][targetChar] == INT_MAX) {
                return -1;
            }

            // Add the minimum cost for this character conversion
            totalCost += minCostMatrix[sourceChar][targetChar];
        }

        return totalCost;
    }
};
