# Solution for Minimum Equal Sum of Two Arrays After Replacing Zeros in PY

class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        sum1, sum2, zero1, zero2 = 0, 0, 0, 0
        for num in nums1:
            sum1 += 1 if num == 0 else num
            zero1 += 1 if num == 0 else 0
        for num in nums2:
            sum2 += 1 if num == 0 else num
            zero2 += 1 if num == 0 else 0
        return -1 if ((sum1 < sum2 and zero1 == 0) or (sum2 < sum1 and zero2 == 0)) else max(sum1, sum2)
