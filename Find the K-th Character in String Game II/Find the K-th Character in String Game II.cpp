// Solution for Find the K-th Character in String Game II in CPP

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // Base case: the initial string is just "a"
        if (k == 1) return 'a';

        int opCount = operations.size();
        long long currentLength = 1;
        long long reducedK = -1;
        int operationType = 0;

        // Step 1: Determine the operation that generated the kth character
        for (int i = 0; i < opCount; i++) {
            currentLength *= 2;

            if (currentLength >= k) {
                operationType = operations[i];
                reducedK = k - currentLength / 2; // map k to the original half
                break;
            }
        }

        // Step 2: Recurse on the position in the previous half
        char prevChar = kthCharacter(reducedK, operations);

        // Step 3: Apply the current operation to get the final character
        if (operationType == 0) {
            return prevChar;
        } else {
            return (prevChar == 'z') ? 'a' : prevChar + 1;
        }
    }
};
