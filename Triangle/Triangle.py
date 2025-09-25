# Solution for Triangle in PY

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = triangle[-1] # last row
        
        for row in range(len(triangle) - 2, -1, -1):
            for col in range(row + 1):
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1])
    
        return dp[0]
