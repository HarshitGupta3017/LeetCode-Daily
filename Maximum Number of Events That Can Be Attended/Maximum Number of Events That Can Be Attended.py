# Solution for Maximum Number of Events That Can Be Attended in PY

class Solution:
    def maxEvents(self, events: list[list[int]]) -> int:
        events.sort()  # Sort by start day
        min_heap = []
        day = events[0][0]
        total_attended = 0
        i = 0
        n = len(events)

        while i < n or min_heap:
            if not min_heap:
                day = events[i][0]

            # Add all events starting today
            while i < n and events[i][0] == day:
                heapq.heappush(min_heap, events[i][1])  # Push end day
                i += 1

            # Attend the event that ends earliest
            if min_heap:
                heapq.heappop(min_heap)
                total_attended += 1

            day += 1

            # Remove expired events
            while min_heap and min_heap[0] < day:
                heapq.heappop(min_heap)

        return total_attended
