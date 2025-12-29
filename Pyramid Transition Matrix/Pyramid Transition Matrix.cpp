// Solution for Pyramid Transition Matrix in CPP

class Solution {
public:
    /**
     * Recursive helper to determine if a valid pyramid can be built.
     *
     * @param currentRow   Current row we are processing
     * @param transitions Map of allowed bottom-pair → possible top blocks
     * @param index        Current index in currentRow
     * @param nextRow      Row being built above currentRow
     * @param memo         Memoization cache to avoid recomputation
     */
    bool buildPyramid(string currentRow,
                      unordered_map<string, vector<char>>& transitions,
                      int index,
                      string nextRow,
                      unordered_map<string, bool>& memo) {

        // Base case: reached the top of the pyramid
        if (currentRow.length() == 1) {
            return true;
        }

        // Memoization key captures full recursive state
        string stateKey = currentRow + "_" + to_string(index) + "_" + nextRow;
        if (memo.count(stateKey)) {
            return memo[stateKey];
        }

        // If we've processed all adjacent pairs in the current row,
        // move to the next row above
        if (index == currentRow.length() - 1) {
            return memo[stateKey] =
                buildPyramid(nextRow, transitions, 0, "", memo);
        }

        // Extract the current adjacent block pair
        string blockPair = currentRow.substr(index, 2);

        // If no allowed transition exists for this pair, fail early
        if (!transitions.count(blockPair)) {
            return memo[stateKey] = false;
        }

        // Try all possible blocks that can sit on this pair
        for (char topBlock : transitions[blockPair]) {
            nextRow.push_back(topBlock);

            // Recursively attempt to build further
            if (buildPyramid(currentRow, transitions, index + 1, nextRow, memo)) {
                return memo[stateKey] = true;
            }

            // Backtrack
            nextRow.pop_back();
        }

        // No valid configuration found
        return memo[stateKey] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {

        // Build transition map: bottom pair → possible top blocks
        unordered_map<string, vector<char>> transitions;
        for (const string& pattern : allowed) {
            transitions[pattern.substr(0, 2)].push_back(pattern[2]);
        }

        // Memoization cache
        unordered_map<string, bool> memo;

        // Start building from the bottom row
        return buildPyramid(bottom, transitions, 0, "", memo);
    }
};
