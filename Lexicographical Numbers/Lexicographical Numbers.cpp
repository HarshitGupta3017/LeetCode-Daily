// Solution for Lexicographical Numbers in CPP

class Solution {
public:

    // Recursive function to build lexicographical numbers
    void generateLexical(int currentNum, int n, vector<int>& result) {
        if (currentNum > n) return;

        result.push_back(currentNum);

        for (int digit = 0; digit <= 9; digit++) {
            int nextNum = currentNum * 10 + digit;
            if (nextNum > n) return;
            generateLexical(nextNum, n, result);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;

        // Start from digits 1 to 9 (valid starting numbers)
        for (int start = 1; start <= 9; start++) {
            generateLexical(start, n, result);
        }

        return result;
    }
};
