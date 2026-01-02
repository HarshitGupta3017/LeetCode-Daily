# Solution for N-Repeated Element in Size 2N Array in PY

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        seen = set()
        for num in nums:
            if num in seen:
                return num
            seen.add(num)

        return 0 
