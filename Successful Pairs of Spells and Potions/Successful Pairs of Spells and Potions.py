# Solution for Successful Pairs of Spells and Potions in PY

class Solution:
    def successfulPairs(self, spells, potions, success):
        
        # Get the number of spells and potions
        num_spells = len(spells)
        num_potions = len(potions)
        
        # List to store the result: number of successful pairs for each spell
        successful_pair_counts = [0] * num_spells
        
        # Sort the potion strengths to enable binary search
        potions.sort()
        
        # Iterate through each spell
        for spell_index in range(num_spells):
            
            # Calculate the minimum potion strength required for a successful pair
            min_potion_strength_required = (success + spells[spell_index] - 1) // spells[spell_index]
            
            # Use binary search to find the first potion that satisfies the requirement
            first_valid_potion_index = bisect_left(potions, min_potion_strength_required)
            
            # Number of successful pairs is total potions minus index of first valid one
            successful_pair_counts[spell_index] = num_potions - first_valid_potion_index
        
        # Return the result list
        return successful_pair_counts
