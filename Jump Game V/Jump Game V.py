# Solution for Jump Game V in PY

class Solution:
    def maxJumps(self, arr, d):

        total_elements = len(arr)

        # dp[i] stores maximum indices that can be visited
        # starting from index i
        dp = [1] * total_elements

        # Store (value, index) pairs
        # to process smaller elements first
        sorted_elements = []

        for index in range(total_elements):
            sorted_elements.append((arr[index], index))

        sorted_elements.sort()

        # Process indices in increasing order of values
        for value, current_index in sorted_elements:

            best_reach = 1

            # Explore left side within jump distance
            for next_index in range(current_index - 1,
                                    max(-1, current_index - d - 1),
                                    -1):

                # Cannot jump across equal or larger element
                if arr[next_index] >= arr[current_index]:
                    break

                best_reach = max(best_reach, 1 + dp[next_index])

            # Explore right side within jump distance
            for next_index in range(current_index + 1,
                                    min(total_elements, current_index + d + 1)):

                # Cannot jump across equal or larger element
                if arr[next_index] >= arr[current_index]:
                    break

                best_reach = max(best_reach, 1 + dp[next_index])

            dp[current_index] = best_reach

        # Maximum reachable indices from any starting point
        return max(dp)
