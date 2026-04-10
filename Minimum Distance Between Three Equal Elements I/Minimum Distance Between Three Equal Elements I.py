# Solution for Minimum Distance Between Three Equal Elements I in PY

class Solution:
    def minimumDistance(self, nums):
        # Map each value to list of indices
        value_to_indices = defaultdict(list)

        for i, num in enumerate(nums):
            value_to_indices[num].append(i)

        minimum_distance = float('inf')

        # Iterate over each value
        for indices in value_to_indices.values():
            if len(indices) < 3:
                continue

            for left in range(len(indices) - 2):
                right = left + 2
                current_distance = 2 * (indices[right] - indices[left])
                minimum_distance = min(minimum_distance, current_distance)

        return -1 if minimum_distance == float('inf') else minimum_distance
