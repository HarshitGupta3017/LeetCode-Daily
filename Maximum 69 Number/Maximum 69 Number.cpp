// Solution for Maximum 69 Number in CPP

class Solution {
public:
    int maximum69Number(int num) {
        int tempNum = num;                 // Copy of the number for processing
        int digitPosition = 0;             // Tracks current digit position (units, tens, etc.)
        int leftmostSixPosition = -1;      // Stores the position of the *leftmost* 6 found
        
        // Traverse through all digits of the number
        while (tempNum > 0) {
            int currentDigit = tempNum % 10;   // Extract last digit
            
            // If digit is 6, update its position
            if (currentDigit == 6) {
                leftmostSixPosition = digitPosition;
            }
            
            tempNum /= 10;   // Remove last digit
            digitPosition++; // Move to next digit position
        }
        
        // If no '6' was found, return original number
        // Otherwise, change the *leftmost 6* into a 9
        return (leftmostSixPosition == -1) 
            ? num 
            : num + 3 * pow(10, leftmostSixPosition);
    }
};
