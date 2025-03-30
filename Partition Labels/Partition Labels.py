# Solution for Partition Labels in PY

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        n = len(s)
        mp = [-1] * 26
        for i in range(n):
            mp[ord(s[i]) - ord('a')] = i
        i, start, end = 0, 0, 0
        result = []
        while i < n:
            end = max(end, mp[ord(s[i]) - ord('a')])
            if i == end:
                result.append(end - start + 1)
                start = end + 1
            i += 1
        return result
