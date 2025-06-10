# Solution for Maximum Difference Between Even and Odd Frequency I in PY

class Solution:
    def maxDifference(self, s: str) -> int:
        charFreq = [0] * 26
        for ch in s:
            charFreq[ord(ch) - ord('a')] += 1
        
        maxOddFreq = 0
        minEvenFreq = sys.maxsize
        
        for i in range(26):
            if charFreq[i] == 0:
                continue
            
            if charFreq[i] % 2 == 0:
                minEvenFreq = min(minEvenFreq, charFreq[i])
            else:
                maxOddFreq = max(maxOddFreq, charFreq[i])
        
        return maxOddFreq - minEvenFreq
