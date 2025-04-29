# Solution for Count Subarrays Where Max Element Appears at Least K Times in PY

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        i, j, res, count, n, mx = 0, 0, 0, 0, len(nums), max(nums)
        while j < n:
            if nums[j] == mx:
                count += 1
            while count >= k:
                res += (n - j)
                if nums[i] == mx:
                    count -= 1
                i += 1
            j += 1
        return res
