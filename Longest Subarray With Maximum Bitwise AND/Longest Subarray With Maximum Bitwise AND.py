# Solution for Longest Subarray With Maximum Bitwise AND in PY

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        maxLength = currentLength = maxVal = 0
        
        for num in nums:
            if num > maxVal:
                maxVal = num       
                currentLength = 1
                maxLength = 1  
    
            elif num == maxVal:
                currentLength += 1
                maxLength = max(maxLength, currentLength)
        
            else:
                currentLength = 0

        return maxLength
