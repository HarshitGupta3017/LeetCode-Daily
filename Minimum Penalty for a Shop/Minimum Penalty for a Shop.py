# Solution for Minimum Penalty for a Shop in PY

class Solution:
    def bestClosingTime(self, customers: str) -> int:

        total_hours = len(customers)

        # Current penalty difference
        current_penalty = 0

        # Track minimum penalty encountered
        minimum_penalty = 0

        # Store earliest hour with minimum penalty
        best_hour_to_close = 0

        # Iterate through each hour, considering closing AFTER this hour
        for hour in range(total_hours):

            if customers[hour] == 'Y':
                current_penalty -= 1
            else:
                current_penalty += 1

            # Update best closing time if lower penalty found
            if current_penalty < minimum_penalty:
                minimum_penalty = current_penalty
                best_hour_to_close = hour + 1

        return best_hour_to_close
