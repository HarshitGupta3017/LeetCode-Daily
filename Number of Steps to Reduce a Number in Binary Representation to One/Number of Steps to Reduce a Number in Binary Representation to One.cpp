// Solution for Number of Steps to Reduce a Number in Binary Representation to One in CPP

class Solution {
public:
    int numSteps(string s) {
        
        int length = s.size();              // Length of the binary string
        int totalOperations = 0;            // Counts total steps required
        int carryFromAddition = 0;          // Simulates carry when we add 1 to an odd number
        
        // Traverse from right to left (least significant bit to most significant bit)
        // We stop at index > 0 because we don't process the leftmost bit here
        for (int index = length - 1; index > 0; index--) {
            
            // Convert current character ('0' or '1') into integer (0 or 1)
            int currentBit = s[index] - '0';
            
            // Add carry (if previous operation caused an addition overflow)
            int effectiveBit = currentBit + carryFromAddition;
            
            // If effectiveBit is even (0 or 2)
            // That means number is even → we just divide by 2
            if (effectiveBit % 2 == 0) {
                
                // One operation: divide by 2
                totalOperations++;
                
            } else {
                // If effectiveBit is odd (1)
                // Odd number → first add 1 (makes it even)
                // Then divide by 2
                
                // Two operations:
                // 1) Add 1
                // 2) Divide by 2
                totalOperations += 2;
                
                // Adding 1 causes a carry to the next left bit
                carryFromAddition = 1;
            }
        }
        
        // After finishing all bits except the leftmost one,
        // if carry is still 1, we need one final operation.
        // Example: "111" → becomes "1000"
        // That extra carry needs one more step.
        return totalOperations + carryFromAddition;
    }
};
