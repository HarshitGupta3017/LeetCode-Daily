# Solution for Check If All 1's Are at Least Length K Places Away in PY

class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        prev = -1
        for curr in range(len(nums)):
            if nums[curr] == 0:
                continue
            if prev != -1 and curr - prev - 1 < k:
                return False
            prev = curr
        return True
