# Solution for Length of Longest Subarray With at Most K Frequency in PY

class Solution:
    def maxSubarrayLength(self, nums, k):
        n = len(nums)
        left = 0
        right = 0
        max_len = 0

        freq = {}

        while right < n:
            freq[nums[right]] = freq.get(nums[right], 0) + 1

            while freq[nums[right]] > k:
                freq[nums[left]] -= 1
                left += 1

            max_len = max(max_len, right - left + 1)
            right += 1

        return max_len
