# Solution for Maximum Number of Events That Can Be Attended II in PY

class Solution:
    def maxValue(self, events: list[list[int]], k: int) -> int:
        events.sort()
        n = len(events)
        from functools import lru_cache

        @lru_cache(None)
        def getMax(idx, rem):
            if idx >= n or rem == 0:
                return 0
            skip = getMax(idx + 1, rem)
            next_idx = idx + 1
            while next_idx < n and events[next_idx][0] <= events[idx][1]:
                next_idx += 1
            take = events[idx][2] + getMax(next_idx, rem - 1)
            return max(skip, take)

        return getMax(0, k)
