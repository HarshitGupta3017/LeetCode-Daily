// Solution for Number of Steps to Reduce a Number in Binary Representation to One in JAVA

class Solution {
    public int numSteps(String s) {
        
        int length = s.length();       // Length of the binary string
        int totalOperations = 0;       // Counts total steps required
        int carryFromAddition = 0;     // Simulates carry when we add 1
        
        // Traverse from right to left (least significant bit to most significant bit)
        for (int index = length - 1; index > 0; index--) {
            
            // Convert current character ('0' or '1') into integer (0 or 1)
            int currentBit = s.charAt(index) - '0';
            
            // Add carry
            int effectiveBit = currentBit + carryFromAddition;
            
            // If even → divide by 2
            if (effectiveBit % 2 == 0) {
                totalOperations++;
            } 
            // If odd → add 1 then divide by 2
            else {
                totalOperations += 2;
                carryFromAddition = 1;
            }
        }
        
        // Add remaining carry if exists
        return totalOperations + carryFromAddition;
    }
}
