// Solution for Jump Game V in CPP

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {

        int totalElements = arr.size();

        // dp[i] stores maximum indices that can be visited
        // starting from index i
        vector<int> dp(totalElements, 1);

        // Store {value, index} pairs
        // to process smaller elements first
        vector<pair<int, int>> sortedElements;

        for (int index = 0; index < totalElements; index++) {

            sortedElements.push_back({arr[index], index});
        }

        sort(sortedElements.begin(), sortedElements.end());

        // Process indices in increasing order of values
        for (const auto& element : sortedElements) {

            int currentIndex = element.second;

            int bestReach = 1;

            // Explore left side within jump distance
            for (int nextIndex = currentIndex - 1; nextIndex >= max(0, currentIndex - d); nextIndex--) {

                // Cannot jump across equal or larger element
                if (arr[nextIndex] >= arr[currentIndex]) {

                    break;
                }

                bestReach = max(bestReach, 1 + dp[nextIndex]);
            }

            // Explore right side within jump distance
            for (int nextIndex = currentIndex + 1; nextIndex <= min(totalElements - 1, currentIndex + d); nextIndex++) {

                // Cannot jump across equal or larger element
                if (arr[nextIndex] >= arr[currentIndex]) {

                    break;
                }

                bestReach = max(bestReach, 1 + dp[nextIndex]);
            }

            dp[currentIndex] = bestReach;
        }

        // Maximum reachable indices from any starting point
        return *max_element(dp.begin(), dp.end());
    }
};
