# Solution for Count the Number of Good Subarrays in PY

class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        i, j, res, pairs = 0, 0, 0, 0
        mp = {}
        n = len(nums)
        while j < n:
            pairs += mp.get(nums[j], 0)
            mp[nums[j]] = mp.get(nums[j], 0) + 1
            while pairs >= k:
                res += n - j
                mp[nums[i]] -= 1
                pairs -= mp[nums[i]]
                i += 1
            j += 1
        return res
