# Solution for Count Subarrays With Majority Element I in PY

class Solution:
    def countMajoritySubarrays(self, nums: list[int], target: int) -> int:
        n = len(nums)
        result = 0

        for left in range(n):
            target_count = 0

            for right in range(left, n):
                if nums[right] == target:
                    target_count += 1

                subarray_len = right - left + 1

                # target is a majority if it appears more than half the time
                if target_count * 2 > subarray_len:
                    result += 1

        return result
