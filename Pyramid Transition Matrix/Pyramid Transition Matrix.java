// Solution for Pyramid Transition Matrix in JAVA

class Solution {

    /**
     * Recursive helper to determine if a valid pyramid can be built.
     *
     * @param currentRow  Current row being processed
     * @param transitions Map of allowed bottom-pair → possible top blocks
     * @param index       Current index in currentRow
     * @param nextRow     Row being built above currentRow
     * @param memo        Memoization cache
     */
    private boolean buildPyramid(String currentRow,
                                 Map<String, List<Character>> transitions,
                                 int index,
                                 StringBuilder nextRow,
                                 Map<String, Boolean> memo) {

        // Base case: reached the top of the pyramid
        if (currentRow.length() == 1) {
            return true;
        }

        // Memoization key captures full recursive state
        String stateKey = currentRow + "_" + index + "_" + nextRow.toString();
        if (memo.containsKey(stateKey)) {
            return memo.get(stateKey);
        }

        // Finished processing current row → move to next row
        if (index == currentRow.length() - 1) {
            boolean result = buildPyramid(
                nextRow.toString(), transitions, 0, new StringBuilder(), memo
            );
            memo.put(stateKey, result);
            return result;
        }

        // Current adjacent block pair
        String blockPair = currentRow.substring(index, index + 2);

        // No valid transition
        if (!transitions.containsKey(blockPair)) {
            memo.put(stateKey, false);
            return false;
        }

        // Try all possible top blocks
        for (char topBlock : transitions.get(blockPair)) {
            nextRow.append(topBlock);

            if (buildPyramid(currentRow, transitions, index + 1, nextRow, memo)) {
                memo.put(stateKey, true);
                return true;
            }

            // Backtrack
            nextRow.deleteCharAt(nextRow.length() - 1);
        }

        memo.put(stateKey, false);
        return false;
    }

    public boolean pyramidTransition(String bottom, List<String> allowed) {

        // Build transition map
        Map<String, List<Character>> transitions = new HashMap<>();
        for (String pattern : allowed) {
            transitions
                .computeIfAbsent(pattern.substring(0, 2), k -> new ArrayList<>())
                .add(pattern.charAt(2));
        }

        // Memoization cache
        Map<String, Boolean> memo = new HashMap<>();

        // Start DFS from bottom row
        return buildPyramid(bottom, transitions, 0, new StringBuilder(), memo);
    }
}
