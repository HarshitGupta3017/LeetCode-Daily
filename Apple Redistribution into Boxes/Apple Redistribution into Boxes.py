# Solution for Apple Redistribution into Boxes in PY

class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:

        # Sort capacities in descending order
        capacity.sort(reverse=True)

        # Calculate total apples
        total_apples = sum(apple)

        count = 0

        # Use largest capacity boxes first
        for cap in capacity:
            if total_apples <= 0:
                break
            total_apples -= cap
            count += 1

        return count
