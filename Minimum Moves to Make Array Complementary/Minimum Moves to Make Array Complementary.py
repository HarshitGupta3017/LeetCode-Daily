# Solution for Minimum Moves to Make Array Complementary in PY

class Solution:
    def minMoves(self, nums, limit):

        total_elements = len(nums)

        # Difference array to track move cost changes
        difference_array = [0] * (2 * limit + 2)

        # Process each complementary pair
        for index in range(total_elements // 2):

            left_value = nums[index]
            right_value = nums[total_elements - index - 1]

            current_sum = left_value + right_value

            # Minimum sum achievable with one move
            minimum_one_move_sum = min(left_value, right_value) + 1

            # Maximum sum achievable with one move
            maximum_one_move_sum = max(left_value, right_value) + limit

            # Default cost = 2 moves
            difference_array[2] += 2
            difference_array[2 * limit + 1] -= 2

            # Cost reduces to 1 move
            difference_array[minimum_one_move_sum] -= 1
            difference_array[maximum_one_move_sum + 1] += 1

            # Cost reduces to 0 moves
            difference_array[current_sum] -= 1
            difference_array[current_sum + 1] += 1

        minimum_moves = float('inf')

        # Build prefix sum
        for target_sum in range(2, 2 * limit + 1):

            difference_array[target_sum] += difference_array[target_sum - 1]

            minimum_moves = min(minimum_moves, difference_array[target_sum])

        return minimum_moves
