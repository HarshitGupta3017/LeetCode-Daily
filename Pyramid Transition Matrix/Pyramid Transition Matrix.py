# Solution for Pyramid Transition Matrix in PY

from typing import List, Dict

class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:

        # Build transition map: bottom pair -> possible top blocks
        transitions: Dict[str, List[str]] = {}
        for pattern in allowed:
            transitions.setdefault(pattern[:2], []).append(pattern[2])

        memo = {}

        def build_pyramid(current_row: str, index: int, next_row: str) -> bool:
            # Base case: reached the top
            if len(current_row) == 1:
                return True

            # Memoization key
            state_key = (current_row, index, next_row)
            if state_key in memo:
                return memo[state_key]

            # Finished processing current row → move up
            if index == len(current_row) - 1:
                memo[state_key] = build_pyramid(next_row, 0, "")
                return memo[state_key]

            # Current adjacent block pair
            block_pair = current_row[index:index + 2]

            # No valid transition
            if block_pair not in transitions:
                memo[state_key] = False
                return False

            # Try all possible top blocks
            for top_block in transitions[block_pair]:
                if build_pyramid(current_row, index + 1, next_row + top_block):
                    memo[state_key] = True
                    return True

            memo[state_key] = False
            return False

        # Start DFS from bottom row
        return build_pyramid(bottom, 0, "")
