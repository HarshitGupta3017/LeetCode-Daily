# Solution for Maximum Matching of Players With Trainers in PY

class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()

        i = j = matched = 0

        while i < len(players) and j < len(trainers):
            if players[i] <= trainers[j]:
                matched += 1
                i += 1
            j += 1

        return matched
