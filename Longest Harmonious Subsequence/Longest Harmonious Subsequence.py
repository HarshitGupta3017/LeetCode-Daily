# Solution for Longest Harmonious Subsequence in PY

class Solution:
    def findLHS(self, nums: List[int]) -> int:
        freq_map = Counter(nums)
        max_length = 0

        for num in freq_map:
            if num + 1 in freq_map:
                current_length = freq_map[num] + freq_map[num + 1]
                max_length = max(max_length, current_length)

        return max_length
