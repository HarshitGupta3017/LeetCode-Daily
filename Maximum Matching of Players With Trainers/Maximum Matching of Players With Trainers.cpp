// Solution for Maximum Matching of Players With Trainers in CPP

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // Step 1: Sort both players and trainers in ascending order
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int playerCount = players.size();
        int trainerCount = trainers.size();

        int playerIdx = 0;  // Pointer for players
        int trainerIdx = 0; // Pointer for trainers
        int matchedCount = 0; // Count of successful matches

        // Step 2: Try to match each player with the current or next available trainer
        while (playerIdx < playerCount && trainerIdx < trainerCount) {
            if (players[playerIdx] <= trainers[trainerIdx]) {
                // Match found, move to next player and trainer
                matchedCount++;
                playerIdx++;
            }
            // Move to next trainer in both cases (match or no match)
            trainerIdx++;
        }

        // Step 3: Return total number of matched pairs
        return matchedCount;
    }
};
