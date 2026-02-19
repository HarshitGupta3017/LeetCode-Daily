# Solution for Count Binary Substrings in PY

class Solution:
    def countBinarySubstrings(self, s: str) -> int:

        total_substrings = 0

        # Length of the previous consecutive group (e.g., "000")
        previous_group_length = 0

        # Length of the current consecutive group
        current_group_length = 1  # First character starts a group

        # Start from second character
        for i in range(1, len(s)):

            if s[i] == s[i - 1]:
                # Still in the same group → increase current group length
                current_group_length += 1
            else:
                # Group changed (0→1 or 1→0)

                # Add valid substrings from adjacent groups
                total_substrings += min(previous_group_length, current_group_length)

                # Shift current group to previous
                previous_group_length = current_group_length

                # Reset current group length
                current_group_length = 1

        # Add the last pair of groups
        total_substrings += min(previous_group_length, current_group_length)

        return total_substrings
