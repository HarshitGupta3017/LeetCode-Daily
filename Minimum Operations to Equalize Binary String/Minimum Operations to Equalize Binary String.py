# Solution for Minimum Operations to Equalize Binary String in PY

from bisect import bisect_left
from collections import deque

class Solution:
    def minOperations(self, s: str, k: int) -> int:

        length = len(s)
        initial_zero_count = s.count('0')

        if initial_zero_count == 0:
            return 0

        visited = [-1] * (length + 1)

        unvisited_even = [z for z in range(0, length + 1) if z % 2 == 0]
        unvisited_odd = [z for z in range(0, length + 1) if z % 2 == 1]

        def remove_value(arr, value):
            idx = bisect_left(arr, value)
            if idx < len(arr) and arr[idx] == value:
                arr.pop(idx)

        queue = deque([initial_zero_count])
        visited[initial_zero_count] = 0

        if initial_zero_count % 2 == 0:
            remove_value(unvisited_even, initial_zero_count)
        else:
            remove_value(unvisited_odd, initial_zero_count)

        while queue:

            current = queue.popleft()

            min_flipped = max(0, k - (length - current))
            max_flipped = min(k, current)

            min_new = current + k - 2 * max_flipped
            max_new = current + k - 2 * min_flipped

            candidate_set = (
                unvisited_even if min_new % 2 == 0
                else unvisited_odd
            )

            idx = bisect_left(candidate_set, min_new)

            while idx < len(candidate_set) and candidate_set[idx] <= max_new:

                next_zero = candidate_set[idx]
                visited[next_zero] = visited[current] + 1

                if next_zero == 0:
                    return visited[next_zero]

                queue.append(next_zero)
                candidate_set.pop(idx)  # remove visited

        return -1
