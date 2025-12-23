# Solution for Two Best Non-Overlapping Events in PY

from bisect import bisect_right
from typing import List

class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:

        total_events = len(events)

        # Sort events by start time
        events.sort()

        # dp[index][events_taken]
        dp = [[-1] * 3 for _ in range(total_events)]

        def dfs(index: int, events_taken: int) -> int:
            # Base case:
            # If we've already taken 2 events OR no events left
            if events_taken == 2 or index >= total_events:
                return 0

            # Return memoized value if already computed
            if dp[index][events_taken] != -1:
                return dp[index][events_taken]

            # ------------------------------------------------
            # Option 1: Skip current event
            # ------------------------------------------------
            skip_current = dfs(index + 1, events_taken)

            # ------------------------------------------------
            # Option 2: Take current event
            # ------------------------------------------------
            current_end_time = events[index][1]

            # Find next event whose start time > current_end_time
            next_index = bisect_right(
                events,
                current_end_time,
                lo=index + 1,
                key=lambda e: e[0]
            )

            take_current = (
                events[index][2] +
                dfs(next_index, events_taken + 1)
            )

            # Store and return best choice
            dp[index][events_taken] = max(skip_current, take_current)
            return dp[index][events_taken]

        # Start recursion from index 0 with 0 events taken
        return dfs(0, 0)
