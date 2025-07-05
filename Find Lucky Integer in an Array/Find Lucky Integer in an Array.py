# Solution for Find Lucky Integer in an Array in PY

class Solution:
    def findLucky(self, arr: List[int]) -> int:
        n = len(arr)
        for num in arr:
            value = num & 65535
            if value <= n:
                arr[value - 1] += (1 << 16)

        for val in range(n, 0, -1):
            freq = arr[val - 1] >> 16
            if freq == val:
                return val
        return -1
