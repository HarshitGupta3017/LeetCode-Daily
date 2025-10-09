# Solution for Find the Minimum Amount of Time to Brew Potions in PY

class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        total_wizards = len(skill)     # Number of wizards
        total_potions = len(mana)      # Number of potions

        # finish_time[i] → time when the i-th wizard finishes processing the current potion
        finish_time = [0] * total_wizards

        # Process each potion sequentially
        for potion_index in range(total_potions):

            # Wizard 0 always starts first
            finish_time[0] += mana[potion_index] * skill[0]

            # Process through all wizards sequentially
            for wizard_index in range(1, total_wizards):
                # Each wizard must start only after:
                # - they have finished their previous potion, AND
                # - the previous wizard has finished this potion
                finish_time[wizard_index] = max(
                    finish_time[wizard_index],
                    finish_time[wizard_index - 1]
                ) + mana[potion_index] * skill[wizard_index]

            # Adjust timings backward to maintain synchronization
            for wizard_index in range(total_wizards - 1, 0, -1):
                finish_time[wizard_index - 1] = (
                    finish_time[wizard_index]
                    - mana[potion_index] * skill[wizard_index]
                )

        # The total time is when the last wizard finishes the last potion
        return finish_time[-1]
