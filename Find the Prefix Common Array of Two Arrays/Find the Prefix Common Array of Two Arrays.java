// Solution for Find the Prefix Common Array of Two Arrays in JAVA

class Solution {

    public int[] findThePrefixCommonArray(int[] firstPermutation,
                                          int[] secondPermutation) {

        // Length of permutations
        int arrayLength = firstPermutation.length;

        // Final answer array.
        // prefixCommonCount[i] stores number of common elements
        // in prefixes [0...i].
        int[] prefixCommonCount = new int[arrayLength];

        // HashSet stores elements we have already seen
        // while traversing both arrays.
        HashSet<Integer> seenElements = new HashSet<>();

        // Stores current number of common elements.
        int commonElementsSoFar = 0;

        // Traverse both arrays together.
        for (int currentIndex = 0; currentIndex < arrayLength; currentIndex++) {

            // ---------------- PROCESS ELEMENT FROM FIRST ARRAY ----------------

            // If current element already exists in set,
            // it means it was previously seen in second array.
            if (seenElements.contains(firstPermutation[currentIndex])) {

                // So this element is now common.
                commonElementsSoFar++;
            }
            else {

                // First time seeing this element.
                seenElements.add(firstPermutation[currentIndex]);
            }

            // ---------------- PROCESS ELEMENT FROM SECOND ARRAY ----------------

            // If current element already exists in set,
            // it means it was previously seen in first array.
            if (seenElements.contains(secondPermutation[currentIndex])) {

                // So this element is now common.
                commonElementsSoFar++;
            }
            else {

                // First time seeing this element.
                seenElements.add(secondPermutation[currentIndex]);
            }

            // Store current common count in answer array.
            prefixCommonCount[currentIndex] = commonElementsSoFar;
        }

        // Return final result.
        return prefixCommonCount;
    }
}
