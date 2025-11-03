# Solution for Minimum Time to Make Rope Colorful in PY

class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        n = len(neededTime)
        time = 0
        prev_max = 0

        for i in range(n):
            if i > 0 and colors[i] != colors[i - 1]:
                prev_max = 0

            curr = neededTime[i]
            time += min(prev_max, curr)
            prev_max = max(prev_max, curr)

        return time
