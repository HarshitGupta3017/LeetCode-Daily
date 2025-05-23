# Solution for Find the Maximum Sum of Node Values in PY

class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        total_sum = 0
        count_better_with_xor = 0
        min_loss_when_forced_to_not_use_xor = sys.maxsize

        for num in nums:
            xor_value = num ^ k

            if xor_value > num:
                count_better_with_xor += 1
                total_sum += xor_value
            else:
                total_sum += num

            min_loss_when_forced_to_not_use_xor = min(min_loss_when_forced_to_not_use_xor, abs(num - xor_value))

        if count_better_with_xor % 2 == 1:
            return total_sum - min_loss_when_forced_to_not_use_xor

        return total_sum
