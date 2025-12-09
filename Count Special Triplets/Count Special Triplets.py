# Solution for Count Special Triplets in PY

class Solution:
    def specialTriplets(self, nums: List[int]) -> int:

        from collections import defaultdict

        freqLeft = defaultdict(int)
        freqRight = defaultdict(int)

        MOD = 10**9 + 7
        totalTriplets = 0

        # Step 1: Initially all elements are on RIGHT
        for num in nums:
            freqRight[num] += 1

        # Step 2: Iterate with j
        for val in nums:

            # Move val from RIGHT (as j moves forward)
            freqRight[val] -= 1

            needed = 2 * val

            leftCount = freqLeft[needed]
            rightCount = freqRight[needed]

            totalTriplets = (totalTriplets + (leftCount * rightCount) % MOD) % MOD

            # Move current j into LEFT
            freqLeft[val] += 1

        return totalTriplets % MOD
