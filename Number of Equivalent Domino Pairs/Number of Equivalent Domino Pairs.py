# Solution for Number of Equivalent Domino Pairs in PY

class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        mp = defaultdict(int)
        res = 0
        for d in dominoes:
            key = min(d[0], d[1]) * 10 + max(d[0], d[1])
            res += mp[key]
            mp[key] += 1
        return res
