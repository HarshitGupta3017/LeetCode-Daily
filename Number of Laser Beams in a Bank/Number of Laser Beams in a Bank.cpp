// Solution for Number of Laser Beams in a Bank in CPP

class Solution {
public:
    /**
     * @brief Calculates the total number of laser beams between security devices in a bank.
     *
     * Each beam exists between two rows that both contain security devices ('1's),
     * and all rows between them must be empty (contain no '1').
     *
     * @param bank  A vector of binary strings representing the bank floor layout.
     *              - '1' → Security device
     *              - '0' → Empty cell
     *
     * @return int  Total number of laser beams present in the bank.
     */
    int numberOfBeams(vector<string>& bank) {
        int totalBeams = 0;       // Total count of laser beams
        int previousRowDevices = 0; // Count of devices in the last non-empty row

        // Step 1️⃣: Iterate through each row of the bank
        for (const auto& row : bank) {
            // Step 2️⃣: Count number of security devices ('1') in the current row
            int currentRowDevices = count(row.begin(), row.end(), '1');

            // Step 3️⃣: If there were devices in the previous non-empty row,
            // multiply to get the number of beams between them
            totalBeams += (currentRowDevices * previousRowDevices);

            // Step 4️⃣: Update previousRowDevices only if current row is non-empty
            if (currentRowDevices != 0) {
                previousRowDevices = currentRowDevices;
            }
        }

        return totalBeams;
    }
};
