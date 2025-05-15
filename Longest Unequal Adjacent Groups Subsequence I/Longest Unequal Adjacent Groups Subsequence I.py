# Solution for Longest Unequal Adjacent Groups Subsequence I in PY

class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        res = []
        for i in range(len(words)):
            if i == 0 or groups[i] != groups[i - 1]:
                res.append(words[i])
        return res
