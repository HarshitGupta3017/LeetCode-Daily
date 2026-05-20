// Solution for Find the Prefix Common Array of Two Arrays in CPP

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& firstPermutation,
                                         vector<int>& secondPermutation) {
        
        // This vector will store the final answer.
        // prefixCommonCount[i] = number of common elements
        // found in both arrays from index 0 to i.
        vector<int> prefixCommonCount;

        // This set keeps track of elements we have already seen
        // while traversing both arrays together.
        unordered_set<int> seenElements;

        // Stores the current count of common elements.
        int commonElementsSoFar = 0;

        // Traverse both permutations index by index.
        for (int currentIndex = 0; currentIndex < firstPermutation.size(); currentIndex++) {

            // ---------------- PROCESS ELEMENT FROM FIRST ARRAY ----------------

            // If current element from firstPermutation already exists in the set,
            // it means we previously saw it in secondPermutation.
            // Therefore, this element is now common in both prefixes.
            if (seenElements.count(firstPermutation[currentIndex])) {

                // Increase count of common elements.
                commonElementsSoFar++;
            }
            else {

                // Otherwise, insert it into the set
                // because we are seeing it for the first time.
                seenElements.insert(firstPermutation[currentIndex]);
            }

            // ---------------- PROCESS ELEMENT FROM SECOND ARRAY ----------------

            // Same logic for secondPermutation:
            // If element already exists in set,
            // it means it was previously seen in firstPermutation.
            if (seenElements.count(secondPermutation[currentIndex])) {

                // Element is common in both prefixes now.
                commonElementsSoFar++;
            }
            else {

                // First time seeing this element,
                // so insert it into the set.
                seenElements.insert(secondPermutation[currentIndex]);
            }

            // Store the total common count for current prefix.
            prefixCommonCount.push_back(commonElementsSoFar);
        }

        // Return the final prefix common array.
        return prefixCommonCount;
    }
};
