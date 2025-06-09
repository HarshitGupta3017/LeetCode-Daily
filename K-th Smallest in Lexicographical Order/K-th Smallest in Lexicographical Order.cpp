// Solution for K-th Smallest in Lexicographical Order in CPP

class Solution {
public:

    // Count how many numbers exist in the range [prefix, nextPrefix) within bounds [1, n]
    int countNumbersWithPrefix(long prefix, long nextPrefix, int n) {
        int totalCount = 0;
        while (prefix <= n) {
            // We add the count of numbers in the range [prefix, nextPrefix),
            // but we cannot go beyond n, so we take the minimum of nextPrefix and (n + 1).
            // This ensures we only count valid numbers ≤ n even if the range is wider.
            totalCount += min((long)n + 1, nextPrefix) - prefix;
            prefix *= 10;
            nextPrefix *= 10;
        }
        return totalCount;
    }

    int findKthNumber(int n, int k) {
        int current = 1;
        k--; // Since we already consider the first number

        while (k > 0) {
            int count = countNumbersWithPrefix(current, current + 1, n);

            // If k is greater than the count in this prefix subtree, skip this subtree
            if (count <= k) {
                current++; // Go to next sibling
                k -= count;
            } else {
                current *= 10; // Go to the first child (deeper in trie)
                k--; // We've used one step to go deeper
            }
        }

        return current;
    }
};
