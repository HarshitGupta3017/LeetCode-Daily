# Solution for Maximum Area of Longest Diagonal Rectangle in PY

class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        maxDiag, maxArea = 0, 0
        n = len(dimensions)
        
        for l, w in dimensions:
            diag = l*l + w*w
            area = l * w
            if diag > maxDiag:
                maxDiag = diag
                maxArea = area
            
            elif diag == maxDiag:
                maxArea = max(maxArea, area)
            
        return maxArea
