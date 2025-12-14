// Solution for Number of Ways to Divide a Long Corridor in CPP

class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        int corridorLength = corridor.size();

        // -------------------------------------------------
        // STEP 1: Store indices of all seats ('S')
        // -------------------------------------------------
        vector<int> seatIndices;
        for (int index = 0; index < corridorLength; index++) {
            if (corridor[index] == 'S') {
                seatIndices.push_back(index);
            }
        }

        // -------------------------------------------------
        // STEP 2: Validate seat count
        // - Must have seats
        // - Must be even (2 seats per section)
        // -------------------------------------------------
        int totalSeats = seatIndices.size();
        if (totalSeats == 0 || totalSeats % 2 != 0) {
            return 0;
        }

        // -------------------------------------------------
        // STEP 3: Calculate number of ways
        // -------------------------------------------------
        long long ways = 1;

        // The second seat of the first section
        int previousSectionEnd = seatIndices[1];

        // Iterate over every new section start (3rd seat onward)
        for (int i = 2; i < totalSeats; i += 2) {

            // Number of possible divider positions between
            // previous section end and current section start
            int dividerChoices = seatIndices[i] - previousSectionEnd;

            // Multiply choices into result
            ways = (ways * dividerChoices) % MOD;

            // Update end of current section (its second seat)
            previousSectionEnd = seatIndices[i + 1];
        }

        return ways;
    }
};
