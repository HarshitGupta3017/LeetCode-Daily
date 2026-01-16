# Solution for Maximum Square Area by Removing Fences From a Field in PY

class Solution:
    def maximizeSquareArea(self, m, n, hFences, vFences):

        MOD = 10**9 + 7

        # Add boundary fences (cannot be removed)
        hFences.append(1)
        hFences.append(m)
        vFences.append(1)
        vFences.append(n)

        # Sort fence positions
        hFences.sort()
        vFences.sort()

        """
        Store all possible heights formed
        by choosing any two horizontal fences
        """
        possible_heights = set()
        horizontal_count = len(hFences)

        for i in range(horizontal_count):
            for j in range(i + 1, horizontal_count):
                possible_heights.add(hFences[j] - hFences[i])

        """
        Check vertical distances and
        find the largest common distance
        """
        max_square_side = 0
        vertical_count = len(vFences)

        for i in range(vertical_count):
            for j in range(i + 1, vertical_count):
                width = vFences[j] - vFences[i]
                if width in possible_heights:
                    max_square_side = max(max_square_side, width)

        # If no square possible
        if max_square_side == 0:
            return -1

        return (max_square_side * max_square_side) % MOD
