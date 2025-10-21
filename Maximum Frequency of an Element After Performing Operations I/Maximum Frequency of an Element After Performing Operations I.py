# Solution for Maximum Frequency of an Element After Performing Operations I in PY

class Solution:
    def maxFrequency(self, nums, k, numOperations):
        max_val = max(nums) + k
        prefix = [0] * (max_val + 1)
        for v in nums:
            prefix[v] += 1
        for i in range(1, max_val + 1):
            prefix[i] += prefix[i - 1]

        ans = 0
        for target in range(max_val + 1):
            if prefix[target] == 0:
                continue
            left, right = max(target - k, 0), min(target + k, max_val)
            total = prefix[right] - (prefix[left - 1] if left > 0 else 0)
            curr = prefix[target] - (prefix[target - 1] if target > 0 else 0)
            ans = max(ans, curr + min(total - curr, numOperations))
        return ans
