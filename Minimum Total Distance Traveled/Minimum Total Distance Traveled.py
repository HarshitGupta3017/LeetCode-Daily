# Solution for Minimum Total Distance Traveled in PY

class Solution:
    def minimumTotalDistance(self, robot, factory):

        # Sort robots and factories
        robot.sort()
        factory.sort()

        # Expand factory capacities
        factory_positions = []
        for position, capacity in factory:
            factory_positions.extend([position] * capacity)

        n = len(robot)
        m = len(factory_positions)

        # DP table
        dp = [[-1] * (m + 1) for _ in range(n + 1)]

        def solve(robot_idx, pos_idx):
            # Base: all robots assigned
            if robot_idx >= n:
                return 0

            # Base: no slots left
            if pos_idx >= m:
                return float('inf')

            if dp[robot_idx][pos_idx] != -1:
                return dp[robot_idx][pos_idx]

            # Assign current robot
            assign = abs(robot[robot_idx] - factory_positions[pos_idx]) + \
                     solve(robot_idx + 1, pos_idx + 1)

            # Skip current slot
            skip = solve(robot_idx, pos_idx + 1)

            dp[robot_idx][pos_idx] = min(assign, skip)
            return dp[robot_idx][pos_idx]

        return solve(0, 0)
