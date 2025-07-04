// Solution for Find the K-th Character in String Game II in JAVA

class Solution {
    public char kthCharacter(long k, int[] operations) {
        if (k == 1) return 'a';

        long currentLength = 1;
        long reducedK = -1;
        int operationType = 0;

        for (int i = 0; i < operations.length; i++) {
            currentLength *= 2;
            if (currentLength >= k) {
                operationType = operations[i];
                reducedK = k - currentLength / 2;
                break;
            }
        }

        char prevChar = kthCharacter(reducedK, operations);

        if (operationType == 0) {
            return prevChar;
        } else {
            return (prevChar == 'z') ? 'a' : (char)(prevChar + 1);
        }
    }
}
