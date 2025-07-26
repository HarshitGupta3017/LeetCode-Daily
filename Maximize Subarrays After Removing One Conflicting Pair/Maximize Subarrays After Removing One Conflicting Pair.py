# Solution for Maximize Subarrays After Removing One Conflicting Pair in PY

class Solution:
    def maxSubarrays(self, n: int, conflictingPairs: List[List[int]]) -> int:
        conflict_with_left = defaultdict(list)
        for a, b in conflictingPairs:
            larger = max(a, b)
            smaller = min(a, b)
            conflict_with_left[larger].append(smaller)

        max_left = 0
        second_max_left = 0
        valid_subarrays = 0
        extra_gain = [0] * (n + 1)

        for end in range(1, n + 1):
            for left_conflict in conflict_with_left[end]:
                if left_conflict >= max_left:
                    second_max_left = max_left
                    max_left = left_conflict
                elif left_conflict > second_max_left:
                    second_max_left = left_conflict

            valid_subarrays += (end - max_left)
            extra_gain[max_left] += (max_left - second_max_left)

        return valid_subarrays + max(extra_gain)
