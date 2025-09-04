# Solution for Find Closest Person in PY

class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        person1diff, person2diff = abs(z - x), abs(z - y)
        if person1diff < person2diff:
            return 1
        elif person1diff > person2diff:
            return 2
        return 0
