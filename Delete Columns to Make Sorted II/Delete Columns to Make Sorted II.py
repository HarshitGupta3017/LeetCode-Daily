# Solution for Delete Columns to Make Sorted II in PY

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:

        number_of_strings = len(strs)          # Total rows
        string_length = len(strs[0])           # Total columns
        deleted_columns = 0                    # Answer

        # Tracks whether strs[i] < strs[i+1] is already guaranteed
        is_pair_confirmed_sorted = [False] * (number_of_strings - 1)

        # Iterate column by column
        for col in range(string_length):

            should_delete_column = False

            # Step 1: Check if this column breaks lexicographic order
            for row in range(number_of_strings - 1):

                # Only check pairs that are NOT yet confirmed sorted
                if (not is_pair_confirmed_sorted[row] and
                    strs[row][col] > strs[row + 1][col]):

                    # Order violated → must delete this column
                    should_delete_column = True
                    deleted_columns += 1
                    break

            # If column is deleted, move to next column
            if should_delete_column:
                continue

            # Step 2: Lock ordering for pairs resolved by this column
            for row in range(number_of_strings - 1):

                if (not is_pair_confirmed_sorted[row] and
                    strs[row][col] < strs[row + 1][col]):

                    # This pair is permanently sorted
                    is_pair_confirmed_sorted[row] = True

        return deleted_columns
