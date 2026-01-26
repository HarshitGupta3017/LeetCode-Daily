# Solution for Minimum Absolute Difference in PY

class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        
        n = len(arr)
        minDiff = float('inf')

        for i in range(1, n):
            minDiff = min(minDiff, arr[i] - arr[i - 1])

        result = []
        for i in range(1, n):
            diff = arr[i] - arr[i - 1]
            if diff == minDiff:
                result.append([arr[i - 1], arr[i]])
        
        return result
