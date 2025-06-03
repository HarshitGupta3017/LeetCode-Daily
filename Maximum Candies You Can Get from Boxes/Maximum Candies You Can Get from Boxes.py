# Solution for Maximum Candies You Can Get from Boxes in PY

class Solution:
    def dfs(
        self,
        box: int,
        status: List[int],
        candies: List[int],
        keys: List[List[int]],
        containedBoxes: List[List[int]],
        visited: List[bool],
        foundBoxes: Set[int]
    ) -> int:
        # If we've already visited this box, skip it
        if visited[box]:
            return 0

        # If the box is locked, save it for future when we get its key
        if status[box] == 0:
            foundBoxes.add(box)
            return 0

        # Mark the box as visited
        visited[box] = True
        collectedCandies = candies[box]  # Collect candies in current box

        # Recursively explore boxes found inside the current box
        for innerBox in containedBoxes[box]:
            collectedCandies += self.dfs(innerBox, status, candies, keys, containedBoxes, visited, foundBoxes)

        # Use keys found in the current box
        for unlockBox in keys[box]:
            status[unlockBox] = 1  # Mark the box as open
            # If we already found this box before (but it was locked), explore it now
            if unlockBox in foundBoxes:
                collectedCandies += self.dfs(unlockBox, status, candies, keys, containedBoxes, visited, foundBoxes)

        return collectedCandies

    def maxCandies(
        self,
        status: List[int],
        candies: List[int],
        keys: List[List[int]],
        containedBoxes: List[List[int]],
        initialBoxes: List[int]
    ) -> int:
        n = len(candies)
        totalCandies = 0

        visited = [False] * n       # To avoid visiting the same box again
        foundBoxes = set()          # Boxes found but not yet openable

        # Start DFS from each initially available box
        for box in initialBoxes:
            totalCandies += self.dfs(box, status, candies, keys, containedBoxes, visited, foundBoxes)

        return totalCandies
