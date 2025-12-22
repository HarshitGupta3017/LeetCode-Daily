# Solution for Delete Columns to Make Sorted III in PY

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:

        number_of_rows = len(strs)          # Total number of strings
        number_of_columns = len(strs[0])    # Length of each string

        # dp[col] = length of the longest valid column sequence ending at 'col'
        longest_sequence_ending_at = [1] * number_of_columns

        longest_valid_sequence = 1

        # Iterate over each column as the ending column
        for current_col in range(number_of_columns):

            # Try extending sequences ending at previous columns
            for previous_col in range(current_col):

                can_extend = True

                # Check validity across ALL rows
                for row in range(number_of_rows):

                    # If order breaks in any row, extension is invalid
                    if strs[row][previous_col] > strs[row][current_col]:
                        can_extend = False
                        break

                # If column transition is valid, update DP
                if can_extend:
                    longest_sequence_ending_at[current_col] = max(
                        longest_sequence_ending_at[current_col],
                        longest_sequence_ending_at[previous_col] + 1
                    )

            # Track overall LIS
            longest_valid_sequence = max(
                longest_valid_sequence,
                longest_sequence_ending_at[current_col]
            )

        # Minimum deletions = total columns - max columns we can keep
        return number_of_columns - longest_valid_sequence
