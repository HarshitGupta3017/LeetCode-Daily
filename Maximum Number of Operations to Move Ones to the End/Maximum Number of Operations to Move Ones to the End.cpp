// Solution for Maximum Number of Operations to Move Ones to the End in CPP

class Solution {
public:
    // 🔹 Function to compute the maximum number of valid operations
    int maxOperations(string s) {
        int n = s.size();     // Total length of the binary string
        int index = 0;        // Pointer to traverse the string
        int countOnes = 0;    // Tracks number of '1's encountered so far
        int totalOps = 0;     // Stores total number of possible operations

        // 🧩 Traverse through the string character by character
        while (index < n) {
            if (s[index] == '0') {
                // 💡 Every '0' can potentially be paired with all previous '1's
                // For each block of consecutive zeros, we add the total '1's seen so far
                totalOps += countOnes;

                // ⏩ Skip over all consecutive zeros (we handle them as a group)
                while (index < n && s[index] == '0')
                    index++;
            } 
            else {
                // 🔸 If current character is '1', increase count of available '1's
                countOnes++;
                index++;
            }
        }

        // ✅ Return total number of operations possible
        return totalOps;
    }
};
