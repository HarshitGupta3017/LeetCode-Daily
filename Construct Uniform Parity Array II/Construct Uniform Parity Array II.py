# Solution for Construct Uniform Parity Array II in PY

class Solution:
    def uniformArray(self, nums1):
        min_el = min(nums1)

        if min_el % 2 == 1:
            return True

        for num in nums1:
            if num % 2 == 1:
                return False

        return True
