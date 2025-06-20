# Solution for Maximum Manhattan Distance After K Changes in PY

class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        max_distance_reached = 0
        count_n = count_s = count_e = count_w = 0

        for i, ch in enumerate(s):
            if ch == 'N':
                count_n += 1
            elif ch == 'S':
                count_s += 1
            elif ch == 'E':
                count_e += 1
            elif ch == 'W':
                count_w += 1

            current_distance = abs(count_n - count_s) + abs(count_e - count_w)
            steps_so_far = i + 1
            wasted_steps = steps_so_far - current_distance
            convertible_waste = min(2 * k, wasted_steps)
            possible_max_distance = current_distance + convertible_waste

            max_distance_reached = max(max_distance_reached, possible_max_distance)

        return max_distance_reached
