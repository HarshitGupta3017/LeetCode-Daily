// Solution for Longest Subarray With Maximum Bitwise AND in JAVA

class Solution {
    public int longestSubarray(int[] nums) {
        int maxLength = 0;          
        int currentLength = 0;      
        int maxVal = 0;       

        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;       
                currentLength = 1;  
                maxLength = 1;     
            } 
    
            else if (num == maxVal) {
                currentLength++;
                maxLength = Math.max(maxLength, currentLength);
            } 
        
            else {
                currentLength = 0;
            }
        }

        return maxLength;
    }
}
