# Solution for Minimum Absolute Distance Between Mirror Pairs in PY

class Solution:
    def minMirrorPairDistance(self, nums):
        reverse_index_map = {}
        minimum_distance = float('inf')

        def get_reversed_number(number):
            return int(str(number)[::-1])  # removes leading zeros automatically

        for current_index, current_value in enumerate(nums):

            # Check if current value matches any stored reversed value
            if current_value in reverse_index_map:
                previous_index = reverse_index_map[current_value]
                minimum_distance = min(minimum_distance, current_index - previous_index)

            # Store reversed value
            reversed_value = get_reversed_number(current_value)
            reverse_index_map[reversed_value] = current_index

        return -1 if minimum_distance == float('inf') else minimum_distance
