// Solution for Maximum Number of Operations to Move Ones to the End in JAVA

class Solution {
    public int maxOperations(String s) {
        int n = s.length();   // Total length of the binary string
        int index = 0;        // Pointer to traverse the string
        int countOnes = 0;    // Tracks number of '1's encountered so far
        int totalOps = 0;     // Stores total number of possible operations

        // 🧩 Traverse through the string character by character
        while (index < n) {
            if (s.charAt(index) == '0') {
                // 💡 Every '0' can be paired with all previous '1's
                totalOps += countOnes;

                // ⏩ Skip over all consecutive zeros
                while (index < n && s.charAt(index) == '0')
                    index++;
            } else {
                // 🔸 Increment '1' count
                countOnes++;
                index++;
            }
        }

        // ✅ Return total operations possible
        return totalOps;
    }
}
