// Solution for Successful Pairs of Spells and Potions in JAVA

class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        
        // Get the number of spells and potions
        int numSpells = spells.length;
        int numPotions = potions.length;
        
        // Array to store the result: number of successful pairs for each spell
        int[] successfulPairCounts = new int[numSpells];
        
        // Sort the potion strengths to enable binary search
        Arrays.sort(potions);
        
        // Iterate through each spell
        for (int spellIndex = 0; spellIndex < numSpells; spellIndex++) {
            
            // Calculate the minimum potion strength required for a successful pair with the current spell
            long minPotionStrengthRequired = (success + spells[spellIndex] - 1) / spells[spellIndex];
            
            // Use binary search to find the index of the first valid potion
            int firstValidPotionIndex = binarySearch(potions, minPotionStrengthRequired);
            
            // The number of successful potions is total potions minus the index of first valid potion
            successfulPairCounts[spellIndex] = numPotions - firstValidPotionIndex;
        }
        
        // Return the array containing the number of successful pairs for each spell
        return successfulPairCounts;
    }
    
    // Custom binary search to find the first index with value >= target
    private int binarySearch(int[] potions, long target) {
        int left = 0, right = potions.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (potions[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
