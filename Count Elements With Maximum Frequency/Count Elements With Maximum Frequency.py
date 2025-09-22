# Solution for Count Elements With Maximum Frequency in PY

class Solution:
    def maxFrequencyElements(self, nums: list[int]) -> int:
        freq = [0] * 101
        maxFreq = total = 0

        for num in nums:
            freq[num] += 1
            if freq[num] > maxFreq:
                maxFreq = freq[num]
                total = maxFreq
            elif freq[num] == maxFreq:
                total += maxFreq
        return total
