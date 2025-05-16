# Solution for Longest Unequal Adjacent Groups Subsequence II in PY

class Solution:
    def checkHammingDist(self, s1: str, s2: str) -> bool:
        diff = 0
        for a, b in zip(s1, s2):
            if a != b:
                diff += 1
                if diff > 1:
                    return False
        return diff == 1

    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n = len(words)
        dp = [1] * n
        parent = [-1] * n
        longestSub = 1
        longestSubIdx = 0

        for i in range(n):
            for j in range(i):
                if (groups[i] != groups[j] and 
                    len(words[i]) == len(words[j]) and 
                    self.checkHammingDist(words[i], words[j])):
                    
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        parent[i] = j

                        if dp[i] > longestSub:
                            longestSub = dp[i]
                            longestSubIdx = i

        result = []
        while longestSubIdx != -1:
            result.append(words[longestSubIdx])
            longestSubIdx = parent[longestSubIdx]

        result.reverse()
        return result
