# Solution for Lexicographically Minimum String After Removing Stars in PY

class Solution:
    def clearStars(self, s: str) -> str:
        min_heap = []
        s = list(s)  # Convert string to list for mutability

        for i, ch in enumerate(s):
            if ch != '*':
                # Python's heapq is a min-heap, use (char, -index) to simulate same behavior
                heapq.heappush(min_heap, (ch, -i))  # negative index = larger index comes first
            else:
                if min_heap:
                    _, neg_idx = heapq.heappop(min_heap)
                    s[-neg_idx] = '*'  # convert back to positive index and mark as removed

        return ''.join(ch for ch in s if ch != '*')
