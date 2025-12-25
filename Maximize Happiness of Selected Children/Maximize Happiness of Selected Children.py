# Solution for Maximize Happiness of Selected Children in PY

class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:

        # Sort happiness in descending order
        happiness.sort(reverse=True)

        total_happiness = 0

        # Select k children
        for turn in range(k):
            # Happiness decreases by 1 for each previously selected child
            current_happiness = max(happiness[turn] - turn, 0)
            total_happiness += current_happiness

        return total_happiness
