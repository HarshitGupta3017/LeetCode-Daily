# Solution for Closest Equal Element Queries in PY

from bisect import bisect_left
from collections import defaultdict

class Solution:
    def solveQueries(self, nums, queries):
        n = len(nums)

        mp = defaultdict(list)
        for i, v in enumerate(nums):
            mp[v].append(i)

        ans = []
        for q in queries:
            lst = mp[nums[q]]

            if len(lst) == 1:
                ans.append(-1)
                continue

            pos = bisect_left(lst, q)
            size = len(lst)

            prev = lst[(pos - 1) % size]
            nxt = lst[(pos + 1) % size]

            d1 = abs(prev - q)
            d2 = abs(nxt - q)

            ans.append(min(d1, d2, n - d1, n - d2))

        return ans
