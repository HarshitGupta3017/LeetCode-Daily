# Solution for Count Subarrays With Majority Element II in PY

class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:

        prefix_freq = {0: 1}
        prefix_sum = valid_left_count = 0
        result = 0

        for num in nums:
            if num == target:
                valid_left_count += prefix_freq.get(prefix_sum, 0)
                prefix_sum += 1
            else:
                prefix_sum -= 1
                valid_left_count -= prefix_freq.get(prefix_sum, 0)

            prefix_freq[prefix_sum] = prefix_freq.get(prefix_sum, 0) + 1
            result += valid_left_count

        return result
