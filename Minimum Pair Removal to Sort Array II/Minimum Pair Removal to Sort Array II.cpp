// Solution for Minimum Pair Removal to Sort Array II in CPP

class Solution {
public:
    using ll = long long;

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        // For handling large sums, converting array into long long
        vector<ll> values(nums.begin(), nums.end());

        // pair -> {sum, idx}
        // Stores (adjacent pair sum, left index of the pair)
        // Always allows us to extract the minimum-sum adjacent pair
        set<pair<ll, int>> minPairSet;

        // Counts how many adjacent pairs violate non-decreasing order
        int badPairs = 0;

        // Initialize adjacent pair sums and badPairs count
        for (int i = 0; i < n - 1; i++) {
            minPairSet.insert({values[i] + values[i + 1], i});
            if (values[i] > values[i + 1]) badPairs++;
        }

        // Doubly linked list simulation using indices
        vector<int> prevIndex(n), nextIndex(n);
        for (int i = 0; i < n; i++) {
            prevIndex[i] = i - 1;
            nextIndex[i] = i + 1;
        }

        int operations = 0;
        
        // if badPairs > 0 then array is not sorted
        while (badPairs > 0) {
            // Pick the leftmost adjacent pair with minimum sum
            int left = minPairSet.begin()->second;
            int right = nextIndex[left];

            int leftNeighbor = prevIndex[left];
            int rightNeighbor = nextIndex[right];

            // Remove the chosen pair from the set
            minPairSet.erase(minPairSet.begin());

            // This pair itself was a bad pair, so remove its contribution
            if (values[left] > values[right]) badPairs--;

            // Impact on first_left {first_left, (first, second)} {f, (a, b)}
            if (leftNeighbor >= 0) {
                // if earlier f and a were good pair and now became bad pair then bad++
                if (values[leftNeighbor] <= values[left] && 
                    values[leftNeighbor] > values[left] + values[right]) {
                    badPairs++;
                }
                // if earlier f and a were bad pair and now became good pair then bad--
                else if (values[leftNeighbor] > values[left] && 
                         values[leftNeighbor] <= values[left] + values[right]) {
                    badPairs--;
                }
            }

            // Impact on second_right {(first, second), second_right} {(a, b), s}
            if (rightNeighbor < n) {
                // if earlier s and b were good pair and now became bad pair then bad++
                if (values[rightNeighbor] >= values[right] && 
                    values[rightNeighbor] < values[left] + values[right]) {
                    badPairs++;
                }
                // if earlier s and b were bad pair and now became good pair then bad--
                else if (values[rightNeighbor] < values[right] && 
                         values[rightNeighbor] >= values[left] + values[right]) {
                    badPairs--;
                }
            }

            // Now update set as we need to erase the pairs with first and second
            // And add new pair with first + second
            if (leftNeighbor >= 0) {
                // Remove old pair (leftNeighbor, left)
                minPairSet.erase({values[leftNeighbor] + values[left], leftNeighbor});
                // Insert new merged pair
                minPairSet.insert({values[leftNeighbor] + values[left] + values[right], leftNeighbor});
            }

            if (rightNeighbor < n) {
                // Remove old pair (right, rightNeighbor)
                minPairSet.erase({values[right] + values[rightNeighbor], right});
                // Insert new merged pair (left, rightNeighbor)
                minPairSet.insert({values[left] + values[right] + values[rightNeighbor], left});
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
};
