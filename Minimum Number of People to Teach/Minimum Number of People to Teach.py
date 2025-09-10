# Solution for Minimum Number of People to Teach in PY

class Solution:
    def minimumTeachings(self, n: int, userLanguages: list[list[int]], friendships: list[list[int]]) -> int:
        sad = set()
        for a,b in friendships:
            a-=1; b-=1
            if not set(userLanguages[a]) & set(userLanguages[b]):
                sad.add(a); sad.add(b)
        from collections import Counter
        freq = Counter(l for u in sad for l in userLanguages[u])
        return len(sad) - (max(freq.values()) if freq else 0)
