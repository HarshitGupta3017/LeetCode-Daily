# Solution for Count of Interesting Subarrays in PY

class Solution:
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        prefix, res = 0, 0
        freq = defaultdict(int)
        freq[0] = 1
        for num in nums:
            if num % modulo == k:
                prefix += 1
            modPrefix = prefix % modulo
            prevPrefix = (modPrefix - k + modulo) % modulo
            if prevPrefix in freq:
                res += freq[prevPrefix]
            freq[modPrefix] += 1
        return res
