# Solution for Count Subarrays With Score Less Than K in PY

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n, i, j, res, sum = len(nums), 0, 0, 0, 0
        while j < n:
            sum += nums[j]
            while i <= j and sum * (j - i + 1) >= k:
                sum -= nums[i]
                i += 1
            res += (j - i + 1)
            j += 1
        return res
