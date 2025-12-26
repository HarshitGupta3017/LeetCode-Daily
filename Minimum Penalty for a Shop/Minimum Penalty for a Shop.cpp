// Solution for Minimum Penalty for a Shop in CPP

class Solution {
public:
    int bestClosingTime(string customers) {
        int totalHours = customers.length();

        // Current penalty difference as we move the closing time hour by hour.
        // Negative value means fewer penalties so far.
        int currentPenalty = 0;

        // Track the minimum penalty encountered
        int minimumPenalty = 0;

        // Store the earliest hour that gives the minimum penalty
        int bestHourToClose = 0;

        // Iterate through each hour, considering closing AFTER this hour
        for (int hour = 0; hour < totalHours; hour++) {

            // If a customer comes at this hour ('Y'):
            // Closing after this hour avoids a "closed while customers came" penalty
            if (customers[hour] == 'Y') {
                currentPenalty--;
            }
            // If no customer comes ('N'):
            // Keeping the shop open adds an "open with no customers" penalty
            else {
                currentPenalty++;
            }

            // Update the best closing time if we found a lower penalty
            if (currentPenalty < minimumPenalty) {
                minimumPenalty = currentPenalty;
                // Closing happens at the next hour (hour + 1)
                bestHourToClose = hour + 1;
            }
        }

        // Return the earliest hour with the minimum penalty
        return bestHourToClose;
    }
};
