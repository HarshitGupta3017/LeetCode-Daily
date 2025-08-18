# Solution for 24 Game in PY

class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:
        epsilon = 1e-6

        def canMake24(nums: List[float]) -> bool:
            if len(nums) == 1:
                return abs(nums[0] - 24.0) <= epsilon
            for i in range(len(nums)):
                for j in range(len(nums)):
                    if i == j:
                        continue
                    remaining = [nums[k] for k in range(len(nums)) if k != i and k != j]
                    num1, num2 = nums[i], nums[j]
                    results = [num1 + num2, num1 - num2, num2 - num1, num1 * num2]
                    if abs(num2) > 0: results.append(num1 / num2)
                    if abs(num1) > 0: results.append(num2 / num1)
                    for val in results:
                        if canMake24(remaining + [val]):
                            return True
            return False

        return canMake24([float(x) for x in cards])
