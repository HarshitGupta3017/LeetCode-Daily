# Solution for Make Array Elements Equal to Zero in PY

class Solution:
    def simulateProcess(self, nums, curr, dir):
        nums = nums[:]  # Copy to avoid mutation
        n = len(nums)

        while 0 <= curr < n:
            if nums[curr] == 0:
                curr += dir
            else:
                nums[curr] -= 1
                dir = -dir
                curr += dir

        return all(x == 0 for x in nums)

    def countValidSelections(self, nums):
        count = 0
        for i, val in enumerate(nums):
            if val == 0:
                if self.simulateProcess(nums, i, 1):
                    count += 1
                if self.simulateProcess(nums, i, -1):
                    count += 1
        return count
