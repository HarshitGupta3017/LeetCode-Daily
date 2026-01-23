// Solution for Minimum Pair Removal to Sort Array II in CPP

class Solution {

    static class Pair {
        long sum;
        int index;

        Pair(long sum, int index) {
            this.sum = sum;
            this.index = index;
        }
    }

    public int minimumPairRemoval(int[] nums) {
        int n = nums.length;

        // For handling large sums, converting array into long long
        long[] values = new long[n];
        for (int i = 0; i < n; i++) values[i] = nums[i];

        // pair -> {sum, idx}
        // Stores (adjacent pair sum, left index of the pair)
        // Always allows us to extract the minimum-sum adjacent pair
        TreeSet<Pair> minPairSet = new TreeSet<>(
            (a, b) -> {
                if (a.sum != b.sum) return Long.compare(a.sum, b.sum);
                return Integer.compare(a.index, b.index);
            }
        );

        // Counts how many adjacent pairs violate non-decreasing order
        int badPairs = 0;

        // Initialize adjacent pair sums and badPairs count
        for (int i = 0; i < n - 1; i++) {
            minPairSet.add(new Pair(values[i] + values[i + 1], i));
            if (values[i] > values[i + 1]) badPairs++;
        }

        // Doubly linked list simulation using indices
        int[] prevIndex = new int[n];
        int[] nextIndex = new int[n];
        for (int i = 0; i < n; i++) {
            prevIndex[i] = i - 1;
            nextIndex[i] = i + 1;
        }

        int operations = 0;

        // if badPairs > 0 then array is not sorted
        while (badPairs > 0) {
            Pair best = minPairSet.pollFirst();

            int left = best.index;
            int right = nextIndex[left];

            int leftNeighbor = prevIndex[left];
            int rightNeighbor = nextIndex[right];

            // This pair itself was a bad pair, so remove its contribution
            if (values[left] > values[right]) badPairs--;

            // Impact on first_left {first_left, (first, second)} {f, (a, b)}
            if (leftNeighbor >= 0) {
                if (values[leftNeighbor] <= values[left] &&
                    values[leftNeighbor] > values[left] + values[right]) {
                    badPairs++;
                } else if (values[leftNeighbor] > values[left] &&
                           values[leftNeighbor] <= values[left] + values[right]) {
                    badPairs--;
                }
            }

            // Impact on second_right {(first, second), second_right} {(a, b), s}
            if (rightNeighbor < n) {
                if (values[rightNeighbor] >= values[right] &&
                    values[rightNeighbor] < values[left] + values[right]) {
                    badPairs++;
                } else if (values[rightNeighbor] < values[right] &&
                           values[rightNeighbor] >= values[left] + values[right]) {
                    badPairs--;
                }
            }

            // Now update set as we need to erase the pairs with first and second
            // And add new pair with first + second
            if (leftNeighbor >= 0) {
                minPairSet.remove(new Pair(values[leftNeighbor] + values[left], leftNeighbor));
                minPairSet.add(new Pair(values[leftNeighbor] + values[left] + values[right], leftNeighbor));
            }

            if (rightNeighbor < n) {
                minPairSet.remove(new Pair(values[right] + values[rightNeighbor], right));
                minPairSet.add(new Pair(values[left] + values[right] + values[rightNeighbor], left));
                prevIndex[rightNeighbor] = left;
            }

            // Update linked list pointers
            nextIndex[left] = rightNeighbor;

            // Merge the selected pair
            values[left] = values[left] + values[right];

            operations++;
        }

        return operations;
    }
}
