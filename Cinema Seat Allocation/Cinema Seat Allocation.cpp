// Solution for Cinema Seat Allocation in CPP

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        // Encode each row's reserved seats as a bitmask.
        // Bit k is set if seat k in that row is reserved.
        unordered_map<int, int> reservedMask;
        for (const auto& rs : reservedSeats) {
            int row = rs[0], seat = rs[1];
            reservedMask[row] |= (1 << seat);
        }

        // Rows with no reservations can always fit two groups (left + right blocks).
        int totalGroups = (n - (int)reservedMask.size()) * 2;

        // The three valid four-seat blocks per row, encoded as bitmasks.
        // Block A: seats 2-5, Block B: seats 4-7, Block C: seats 6-9.
        const int blockA = (1<<2)|(1<<3)|(1<<4)|(1<<5);
        const int blockB = (1<<4)|(1<<5)|(1<<6)|(1<<7);
        const int blockC = (1<<6)|(1<<7)|(1<<8)|(1<<9);

        for (auto& [row, mask] : reservedMask) {
            bool fitsA = (mask & blockA) == 0;
            bool fitsB = (mask & blockB) == 0;
            bool fitsC = (mask & blockC) == 0;

            if (fitsA && fitsC) {
                // Left and right blocks are both clear — fit two groups.
                // Note: fitsA && fitsC implies fitsB may or may not be clear,
                // but A and C don't overlap so two groups always fit here.
                totalGroups += 2;
            } else if (fitsA || fitsB || fitsC) {
                // At least one block is fully clear — fit one group.
                totalGroups += 1;
            }
        }

        return totalGroups;
    }
};
