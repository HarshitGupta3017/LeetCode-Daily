// Solution for Maximum Matching of Players With Trainers in JAVA

class Solution {
    public int matchPlayersAndTrainers(int[] players, int[] trainers) {
        Arrays.sort(players);
        Arrays.sort(trainers);

        int playerIdx = 0;
        int trainerIdx = 0;
        int matched = 0;

        while (playerIdx < players.length && trainerIdx < trainers.length) {
            if (players[playerIdx] <= trainers[trainerIdx]) {
                matched++;
                playerIdx++;
            }
            trainerIdx++;
        }

        return matched;
    }
}
