// Solution for Divide an Array Into Subarrays With Minimum Cost II in CPP

class Solution {
public:
    using ll = long long;

    /*
        Pair structure:
        - first  -> value of nums[i]
        - second -> index i
        Index is needed to correctly remove elements
        when sliding the window.
    */
    using Pair = pair<ll, ll>;

    ll minimumCost(vector<int>& nums, int k, int dist) {

        int n = nums.size();

        /*
            minKElements:
            - Stores the smallest (k-1) elements in the current window
            - Implemented as a sorted set
            - Largest element among these is removable when size exceeds (k-1)
        */
        set<Pair> minKElements;

        /*
            remainingElements:
            - Stores the rest of the elements in the window
            - Helps rebalance when elements are removed
        */
        set<Pair> remainingElements;

        /*
            currentSum:
            - Sum of values present in minKElements
            - This contributes to the cost of subarrays 2..k
        */
        ll currentSum = 0;

        /*
            We start considering elements from index = 1
            because:
            - First subarray always starts at index 0
            - nums[0] is always included in final answer
        */
        int right = 1;

        /*
            Initial window build:
            We need to allow:
            ik-1 - i1 <= dist
            So indices we consider must lie within a window of size dist
        */
        while (right - dist < 1) {

            minKElements.insert({nums[right], right});
            currentSum += nums[right];

            /*
                Keep only the smallest (k-1) elements
            */
            if (minKElements.size() > k - 1) {
                Pair largest = *minKElements.rbegin();
                minKElements.erase(largest);
                currentSum -= largest.first;
                remainingElements.insert(largest);
            }

            right++;
        }

        ll minCostForSubarrays = LLONG_MAX;

        /*
            Slide the window across the array
        */
        while (right < n) {

            /*
                Add new element entering the window
            */
            minKElements.insert({nums[right], right});
            currentSum += nums[right];

            if (minKElements.size() > k - 1) {
                Pair largest = *minKElements.rbegin();
                minKElements.erase(largest);
                currentSum -= largest.first;
                remainingElements.insert(largest);
            }

            /*
                Update answer with current window’s cost
            */
            minCostForSubarrays = min(minCostForSubarrays, currentSum);

            /*
                Remove element leaving the window
            */
            Pair toRemove = {nums[right - dist], right - dist};

            if (minKElements.count(toRemove)) {

                // Element was contributing to sum
                minKElements.erase(toRemove);
                currentSum -= toRemove.first;

                /*
                    Rebalance:
                    Move smallest from remainingElements
                    back into minKElements
                */
                if (!remainingElements.empty()) {
                    Pair smallest = *remainingElements.begin();
                    remainingElements.erase(smallest);
                    minKElements.insert(smallest);
                    currentSum += smallest.first;
                }

            } else {
                // Element was not contributing to sum
                remainingElements.erase(toRemove);
            }

            right++;
        }

        /*
            Final result:
            - nums[0] → cost of first subarray
            - minCostForSubarrays → cost of subarrays 2..k
        */
        return nums[0] + minCostForSubarrays;
    }
};
