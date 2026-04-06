# Solution for Walking Robot Simulation in PY

class Solution:
    def robotSim(self, commands, obstacles):

        # STEP 1: Store obstacles
        obstacle_set = set()
        for x, y in obstacles:
            obstacle_set.add((x, y))

        # STEP 2: Initialize
        x, y = 0, 0
        max_distance_squared = 0

        # Facing NORTH
        dx, dy = 0, 1

        # STEP 3: Process commands
        for command in commands:

            # Turn Left
            if command == -2:
                dx, dy = -dy, dx

            # Turn Right
            elif command == -1:
                dx, dy = dy, -dx

            # Move Forward
            else:
                for _ in range(command):
                    next_x = x + dx
                    next_y = y + dy

                    # Stop if obstacle
                    if (next_x, next_y) in obstacle_set:
                        break

                    x, y = next_x, next_y

            # Update max distance
            max_distance_squared = max(max_distance_squared, x*x + y*y)

        return max_distance_squared
