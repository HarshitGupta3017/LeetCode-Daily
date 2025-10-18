# Solution for Maximum Number of Distinct Elements After Operations in PY

class Solution:
    def maxDistinctElements(self, nums: list[int], k: int) -> int:
        nums.sort()
        distinct_count = 0
        last_used = float("-inf")

        for num in nums:
            min_possible = num - k
            max_possible = num + k

            if last_used < min_possible:
                last_used = min_possible
                distinct_count += 1
            elif last_used < max_possible:
                last_used += 1
                distinct_count += 1

        return distinct_count
