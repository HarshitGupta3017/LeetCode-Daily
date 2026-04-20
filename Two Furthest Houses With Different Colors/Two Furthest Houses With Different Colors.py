# Solution for Two Furthest Houses With Different Colors in PY

class Solution:
    def maxDistance(self, colors):
        total_houses = len(colors)
        maximum_distance = 0

        for current_index in range(total_houses):

            # Case 1: Compare with first house
            if colors[current_index] != colors[0]:
                maximum_distance = max(maximum_distance, current_index)

            # Case 2: Compare with last house
            if colors[current_index] != colors[total_houses - 1]:
                maximum_distance = max(maximum_distance, total_houses - 1 - current_index)

        return maximum_distance
