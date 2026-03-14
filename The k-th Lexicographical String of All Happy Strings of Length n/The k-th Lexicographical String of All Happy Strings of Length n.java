// Solution for The k-th Lexicographical String of All Happy Strings of Length n in JAVA

class Solution {

    void generateHappyStrings(
        int n,
        int k,
        StringBuilder currentString,
        StringBuilder kthResult,
        int[] generatedCount
    ) {

        // Base Case
        if (currentString.length() == n) {
            generatedCount[0]++;

            if (generatedCount[0] == k) {
                kthResult.setLength(0);
                kthResult.append(currentString.toString());
            }
            return;
        }

        for (char candidateChar = 'a'; candidateChar <= 'c'; candidateChar++) {

            if (currentString.length() > 0 &&
                currentString.charAt(currentString.length() - 1) == candidateChar)
                continue;

            currentString.append(candidateChar);

            generateHappyStrings(n, k, currentString, kthResult, generatedCount);

            currentString.deleteCharAt(currentString.length() - 1);
        }
    }

    public String getHappyString(int n, int k) {

        int[] generatedCount = new int[1];
        StringBuilder kthResult = new StringBuilder();
        StringBuilder currentString = new StringBuilder();

        generateHappyStrings(n, k, currentString, kthResult, generatedCount);

        return kthResult.toString();
    }
}
