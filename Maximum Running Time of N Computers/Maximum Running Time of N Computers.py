# Solution for Maximum Running Time of N Computers in PY

class Solution:

    # Helper function to check if we can run all computers for 'target_time' minutes
    def can_run_for_target_time(self, batteries: List[int], computer_count: int, target_time: int) -> bool:
        required_total_time = target_time * computer_count  # Total minutes needed
        available_time = 0                                  # Total minutes batteries can contribute

        for battery_capacity in batteries:
            available_time += min(battery_capacity, target_time)
            if available_time >= required_total_time:
                return True

        return False  # Not enough total battery minutes

    def maxRunTime(self, n: int, batteries: List[int]) -> int:

        # Minimum possible time is the smallest battery
        left = min(batteries)

        # Total sum of battery capacities
        total_battery_time = sum(batteries)

        # Maximum possible time if we evenly distribute all battery time
        right = total_battery_time // n

        best_possible_time = 0

        # Binary search to find max run time
        while left <= right:
            mid = left + (right - left) // 2

            if self.can_run_for_target_time(batteries, n, mid):
                best_possible_time = mid
                left = mid + 1  # Try bigger time
            else:
                right = mid - 1 # Try smaller time

        return best_possible_time
