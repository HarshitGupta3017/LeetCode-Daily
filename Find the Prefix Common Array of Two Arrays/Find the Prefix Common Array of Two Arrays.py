# Solution for Find the Prefix Common Array of Two Arrays in PY

class Solution:

    def findThePrefixCommonArray(self, firstPermutation, secondPermutation):

        # This list will store the final answer.
        # prefixCommonCount[i] = number of common elements
        # found in both arrays from index 0 to i.
        prefixCommonCount = []

        # This set stores elements we have already seen
        # while traversing both arrays.
        seenElements = set()

        # Stores current count of common elements.
        commonElementsSoFar = 0

        # Traverse both arrays together index by index.
        for currentIndex in range(len(firstPermutation)):

            # ---------------- PROCESS ELEMENT FROM FIRST ARRAY ----------------

            # If current element from firstPermutation
            # already exists in set,
            # it means it was seen earlier in secondPermutation.
            if firstPermutation[currentIndex] in seenElements:

                # Element is now common in both prefixes.
                commonElementsSoFar += 1

            else:
                # First time seeing this element.
                seenElements.add(firstPermutation[currentIndex])

            # ---------------- PROCESS ELEMENT FROM SECOND ARRAY ----------------

            # If current element from secondPermutation
            # already exists in set,
            # it means it was seen earlier in firstPermutation.
            if secondPermutation[currentIndex] in seenElements:

                # Element is now common in both prefixes.
                commonElementsSoFar += 1

            else:
                # First time seeing this element.
                seenElements.add(secondPermutation[currentIndex])

            # Store current common count.
            prefixCommonCount.append(commonElementsSoFar)

        # Return final prefix common array.
        return prefixCommonCount
