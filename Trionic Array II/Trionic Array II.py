# Solution for Trionic Array II in PY

class Solution:
    def maxSumTrionic(self, nums: List[int]) -> int:
        n = len(nums)

        # Very small negative value to avoid overflow issues
        NEG_INF = -(10**18)

        # memo[index][trend] stores the maximum sum
        memo = [[None] * 4 for _ in range(n + 1)]

        # Recursive DP function
        # index -> current position in nums
        # trend -> current phase of the trionic sequence
        def dfsMaxSum(index: int, trend: int) -> int:
            # Base case: reached the end of the array
            # Valid only if all 3 phases are completed
            if index == n:
                return 0 if trend == 3 else NEG_INF

            # Return cached result if already computed
            if memo[index][trend] is not None:
                return memo[index][trend]

            # Option 1: take the current element
            takeCurrent = NEG_INF

            # Option 2: skip the current element
            skipCurrent = NEG_INF

            # Skipping allowed only before starting the sequence
            if trend == 0:
                skipCurrent = dfsMaxSum(index + 1, 0)

            # If already in final increasing phase, we can take freely
            if trend == 3:
                takeCurrent = nums[index]

            # Try transitions based on the next element
            if index + 1 < n:
                currentValue = nums[index]
                nextValue = nums[index + 1]

                # Phase 0 -> Phase 1
                if trend == 0 and nextValue > currentValue:
                    takeCurrent = max(
                        takeCurrent,
                        currentValue + dfsMaxSum(index + 1, 1)
                    )

                # Phase 1: strictly increasing
                elif trend == 1:
                    if nextValue > currentValue:
                        takeCurrent = max(
                            takeCurrent,
                            currentValue + dfsMaxSum(index + 1, 1)
                        )
                    elif nextValue < currentValue:
                        takeCurrent = max(
                            takeCurrent,
                            currentValue + dfsMaxSum(index + 1, 2)
                        )

                # Phase 2: strictly decreasing
                elif trend == 2:
                    if nextValue < currentValue:
                        takeCurrent = max(
                            takeCurrent,
                            currentValue + dfsMaxSum(index + 1, 2)
                        )
                    elif nextValue > currentValue:
                        takeCurrent = max(
                            takeCurrent,
                            currentValue + dfsMaxSum(index + 1, 3)
                        )

                # Phase 3: final increasing
                elif trend == 3 and nextValue > currentValue:
                    takeCurrent = max(
                        takeCurrent,
                        currentValue + dfsMaxSum(index + 1, 3)
                    )

            # Store and return best result
            memo[index][trend] = max(takeCurrent, skipCurrent)
            return memo[index][trend]

        # Start recursion from index 0 with trend 0
        return dfsMaxSum(0, 0)
