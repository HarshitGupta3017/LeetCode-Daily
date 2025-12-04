# Solution for Count Collisions on a Road in PY

class Solution:
    def countCollisions(self, directions: str) -> int:
        totalCars = len(directions)

        # Step 1: skip leading L cars
        leftIndex = 0
        while leftIndex < totalCars and directions[leftIndex] == 'L':
            leftIndex += 1
        
        # Step 2: skip trailing R cars
        rightIndex = totalCars - 1
        while rightIndex >= 0 and directions[rightIndex] == 'R':
            rightIndex -= 1
        
        # Step 3: count collisions in the middle part
        collisionCount = 0
        while leftIndex <= rightIndex:
            if directions[leftIndex] != 'S':
                collisionCount += 1
            leftIndex += 1
        
        return collisionCount
