# Solution for Left and Right Sum Differences in PY

class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        total_sum = sum(nums)

        left_sum = 0
        right_sum = total_sum
        result = []

        for num in nums:
            right_sum -= num
            result.append(abs(left_sum - right_sum))
            left_sum += num

        return result
