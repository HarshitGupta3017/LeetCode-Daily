// Solution for Lexicographical Numbers in JAVA

class Solution {
    
    // Recursive function to build lexicographical numbers
    public void generateLexical(int currentNum, int n, List<Integer> result) {
        if (currentNum > n) return;

        result.add(currentNum);

        for (int digit = 0; digit <= 9; digit++) {
            int nextNum = currentNum * 10 + digit;
            if (nextNum > n) return;
            generateLexical(nextNum, n, result);
        }
    }

    public List<Integer> lexicalOrder(int n) {
        List<Integer> result = new ArrayList<>();

        // Start from digits 1 to 9
        for (int start = 1; start <= 9; start++) {
            generateLexical(start, n, result);
        }

        return result;
    }
}
