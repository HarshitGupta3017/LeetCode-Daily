# Solution for Rank Transform of an Array in PY

class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        # Work on a sorted copy so the original order is preserved.
        sorted_arr = sorted(arr)

        # Map each unique value to its rank.
        rank_of = {}
        next_rank = 1

        for num in sorted_arr:
            if num not in rank_of:
                rank_of[num] = next_rank
                next_rank += 1

        # Replace each original element with its rank.
        return [rank_of[num] for num in arr]
