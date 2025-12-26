// Solution for Minimum Penalty for a Shop in JAVA

class Solution {
    public int bestClosingTime(String customers) {

        int totalHours = customers.length();

        // Current penalty difference as we move hour by hour
        int currentPenalty = 0;

        // Track minimum penalty encountered
        int minimumPenalty = 0;

        // Store earliest hour with minimum penalty
        int bestHourToClose = 0;

        // Iterate through each hour, considering closing AFTER this hour
        for (int hour = 0; hour < totalHours; hour++) {

            // If a customer comes at this hour ('Y'),
            // closing after this hour avoids a penalty
            if (customers.charAt(hour) == 'Y') {
                currentPenalty--;
            }
            // If no customer comes ('N'),
            // staying open adds a penalty
            else {
                currentPenalty++;
            }

            // Update best closing time if lower penalty found
            if (currentPenalty < minimumPenalty) {
                minimumPenalty = currentPenalty;
                bestHourToClose = hour + 1;
            }
        }

        return bestHourToClose;
    }
}
