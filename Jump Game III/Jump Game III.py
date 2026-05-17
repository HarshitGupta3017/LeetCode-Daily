# Solution for Jump Game III in PY

class Solution:
    def canReach(self, arr, start):

        # Invalid index or already visited
        if start < 0 or start >= len(arr) or arr[start] < 0:
            return False

        # Reached value 0
        if arr[start] == 0:
            return True

        jump = arr[start]

        # Mark as visited
        arr[start] = -1

        # Try forward and backward jumps
        return (self.canReach(arr, start + jump) or
                self.canReach(arr, start - jump))
