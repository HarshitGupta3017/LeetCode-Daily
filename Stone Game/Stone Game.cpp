// Solution for Stone Game in CPP

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // Alice always wins, regardless of the pile values.
        // With an even number of piles, Alice can mentally label them
        // "odd-indexed" and "even-indexed" before the game starts.
        // She then checks which group has the higher total and commits
        // to always picking from that group.
        // Whenever Bob picks from one end, he exposes the next pile from
        // the other group, which Alice then takes — she can always maintain
        // this strategy because the piles alternate between the two groups.
        // Since the total is odd (no ties) and Alice controls which group
        // she collects, she is guaranteed to win.
        return true;
    }
};
