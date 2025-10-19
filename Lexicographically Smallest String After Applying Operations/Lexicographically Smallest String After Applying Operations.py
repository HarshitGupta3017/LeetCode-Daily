# Solution for Lexicographically Smallest String After Applying Operations in PY

class Solution:
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        queue = deque([s])
        visited = {s}
        smallest = s

        while queue:
            curr = queue.popleft()
            smallest = min(smallest, curr)

            # ---- Operation 1: Add 'a' to all odd indices ----
            chars = list(curr)
            for i in range(1, len(chars), 2):
                chars[i] = str((int(chars[i]) + a) % 10)
            added = ''.join(chars)
            if added not in visited:
                visited.add(added)
                queue.append(added)

            # ---- Operation 2: Rotate right by 'b' ----
            rotated = curr[-b:] + curr[:-b]
            if rotated not in visited:
                visited.add(rotated)
                queue.append(rotated)

        return smallest
