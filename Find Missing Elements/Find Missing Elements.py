# Solution for Find Missing Elements in PY

class Solution:
    def findMissingElements(self, nums):
        # Load all present values into a hash set for O(1) membership checks.
        present = set(nums)

        # Find the minimum and maximum values.
        range_min = min(nums)
        range_max = max(nums)

        missing = []

        # Check all interior values.
        for val in range(range_min + 1, range_max):
            if val not in present:
                missing.append(val)

        return missing
