# Solution for Count Complete Subarrays in an Array in PY

class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        st = set(nums)
        i, j, res, unique_ch, n = 0, 0, 0, len(st), len(nums)
        mp = defaultdict(int)
        while j < n:
            mp[nums[j]] += 1
            while len(mp) == unique_ch:
                res += n - j
                mp[nums[i]] -= 1
                if mp[nums[i]] == 0:
                    del mp[nums[i]]
                i += 1
            j += 1
        return res
