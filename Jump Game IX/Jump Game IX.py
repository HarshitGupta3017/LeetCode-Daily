# Solution for Jump Game IX in PY

class Solution:
    def maxValue(self, nums):
        
        totalElements = len(nums)

        # maxPrefix[i] = maximum value from nums[0...i]
        maxPrefix = [0] * totalElements

        # minSuffix[i] = minimum value from nums[i...n-1]
        minSuffix = [0] * totalElements

        # Initialize boundary values
        maxPrefix[0] = nums[0]
        minSuffix[totalElements - 1] = nums[totalElements - 1]

        # Build prefix maximum array
        # Build suffix minimum array
        for index in range(1, totalElements):

            maxPrefix[index] = max(maxPrefix[index - 1], nums[index])

            minSuffix[totalElements - 1 - index] = min(
                minSuffix[totalElements - index],
                nums[totalElements - 1 - index]
            )

        maximumReachable = [0] * totalElements

        # Last position can always reach global prefix maximum till there
        maximumReachable[totalElements - 1] = maxPrefix[totalElements - 1]

        # Process from right to left
        for index in range(totalElements - 2, -1, -1):

            # If there exists a smaller value on the right,
            # then current index can eventually connect further
            if maxPrefix[index] > minSuffix[index + 1]:

                # Inherit answer from right side
                maximumReachable[index] = maximumReachable[index + 1]

            else:

                # Cannot expand further
                maximumReachable[index] = maxPrefix[index]

        return maximumReachable
