// Solution for Minimum Number of Pushes to Type Word I in CPP

class Solution {
public:
    int minimumPushes(string word) {
        // We have 8 keys (2–9), each of which can hold any number of letters.
        // To minimise total pushes, we assign letters greedily:
        // the first 8 letters each cost 1 push (first slot on each key),
        // the next 8 cost 2 pushes (second slot), the next 8 cost 3, and so on.
        // Since all letters in `word` are distinct, we just assign by position.
        int totalPushes = 0;
        for (int i = 0; i < (int)word.size(); i++)
            totalPushes += (i / 8) + 1;

        return totalPushes;
    }
};
