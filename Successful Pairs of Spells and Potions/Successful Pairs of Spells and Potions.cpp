// Solution for Successful Pairs of Spells and Potions in CPP

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        // Get the number of spells and potions
        int numSpells = spells.size(), numPotions = potions.size();
        
        // Vector to store the result: the number of successful pairs for each spell
        vector<int> successfulPairCounts(numSpells);
        
        // Sort the potion strengths to enable binary search
        sort(begin(potions), end(potions));  

        // Iterate through each spell
        for (int spellIndex = 0; spellIndex < numSpells; spellIndex++) {
            
            // Calculate the minimum potion strength required for a successful pair with the current spell
            long long minPotionStrengthRequired = (success + spells[spellIndex] - 1) / spells[spellIndex];
            
            // Use binary search to find the index of the first potion 
            // that can form a successful pair with the current spell
            int firstValidPotionIndex = lower_bound(potions.begin(), potions.end(), minPotionStrengthRequired) - potions.begin();
            
            // The number of successful potions for this spell is the number of potions after the valid potion
            successfulPairCounts[spellIndex] = numPotions - firstValidPotionIndex;
        }
        
        // Return the result array which contains the number of successful pairs for each spell
        return successfulPairCounts;
    }
};
