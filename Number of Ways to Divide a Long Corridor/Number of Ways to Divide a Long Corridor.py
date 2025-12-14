# Solution for Number of Ways to Divide a Long Corridor in PY

class Solution:
    def numberOfWays(self, corridor: str) -> int:
        MOD = 10**9 + 7
        n = len(corridor)

        # STEP 1: Collect indices of all seats ('S')
        seat_indices = [i for i, ch in enumerate(corridor) if ch == 'S']

        # STEP 2: Validate seat count
        total_seats = len(seat_indices)
        if total_seats == 0 or total_seats % 2 != 0:
            return 0

        # STEP 3: Calculate number of ways
        ways = 1

        # Second seat of the first section
        previous_section_end = seat_indices[1]

        # Process each new section
        for i in range(2, total_seats, 2):
            divider_choices = seat_indices[i] - previous_section_end
            ways = (ways * divider_choices) % MOD
            previous_section_end = seat_indices[i + 1]

        return ways
