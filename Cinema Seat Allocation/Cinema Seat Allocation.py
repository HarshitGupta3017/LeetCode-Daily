# Solution for Cinema Seat Allocation in PY

class Solution:
    def maxNumberOfFamilies(self, n, reservedSeats):

        # Encode each row's reserved seats as a bitmask.
        reservedMask = {}

        for row, seat in reservedSeats:
            reservedMask[row] = reservedMask.get(row, 0) | (1 << seat)

        # Rows with no reservations can fit two groups.
        totalGroups = (n - len(reservedMask)) * 2

        # Block A: seats 2-5
        # Block B: seats 4-7
        # Block C: seats 6-9
        blockA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)
        blockB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7)
        blockC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9)

        for mask in reservedMask.values():

            fitsA = (mask & blockA) == 0
            fitsB = (mask & blockB) == 0
            fitsC = (mask & blockC) == 0

            if fitsA and fitsC:
                totalGroups += 2
            elif fitsA or fitsB or fitsC:
                totalGroups += 1

        return totalGroups
