# Solution for Minimum Distance Between Three Equal Elements II in PY

class Solution:
    def minimumDistance(self, nums):
        mp = {}
        ans = float('inf')

        for i, val in enumerate(nums):
            if val in mp:
                prev2, prev1 = mp[val]

                if prev2 != -1:
                    ans = min(ans, 2 * (i - prev2))

                mp[val] = (prev1, i)
            else:
                mp[val] = (-1, i)

        return -1 if ans == float('inf') else ans
