# Solution for Maximum Frequency of an Element After Performing Operations II in PY

class Solution:
    def maxFrequency(self, nums, k, numOperations):
        diff = defaultdict(int)
        freq = defaultdict(int)
        max_val = max(nums) + k

        # Build difference map for each element's reachable range
        for val in nums:
            freq[val] += 1
            left, right = max(val - k, 0), val + k
            diff[left] += 1
            diff[right + 1] -= 1
            diff[val] += 0  # ensure key exists

        max_freq, prefix = 1, 0

        # Traverse sorted possible targets
        for key in sorted(diff):
            prefix += diff[key]
            curr = freq[key]
            convertible = prefix - curr
            used = min(numOperations, convertible)
            max_freq = max(max_freq, curr + used)

        return max_freq
