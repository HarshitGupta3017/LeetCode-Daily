# Solution for Alternating Groups II in PY

class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        n = len(colors)
        N = n + (k - 1)
        newColors = colors + colors[:k - 1]
        i, j, result = 0, 1, 0
        while j < N:
            if newColors[j] == newColors[j - 1]:
                i = j
                j += 1
                continue
            if j - i + 1 == k:
                result += 1
                i += 1
            j += 1
        return result
