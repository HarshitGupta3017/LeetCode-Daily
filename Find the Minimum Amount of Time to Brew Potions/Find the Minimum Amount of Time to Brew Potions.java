// Solution for Find the Minimum Amount of Time to Brew Potions in JAVA

class Solution {
    public long minTime(int[] skill, int[] mana) {
        int totalWizards = skill.length;   // Number of wizards
        int totalPotions = mana.length;    // Number of potions

        // finishTime[i] → time when the i-th wizard finishes processing the current potion
        long[] finishTime = new long[totalWizards];

        // Process each potion sequentially
        for (int potionIndex = 0; potionIndex < totalPotions; potionIndex++) {

            // Wizard 0 always starts first
            finishTime[0] += (long) mana[potionIndex] * skill[0];

            // Process through all wizards sequentially
            for (int wizardIndex = 1; wizardIndex < totalWizards; wizardIndex++) {
                // Each wizard must start only after:
                // - they have finished their previous potion, AND
                // - the previous wizard has finished this potion
                finishTime[wizardIndex] = Math.max(finishTime[wizardIndex],
                        finishTime[wizardIndex - 1]) + (long) mana[potionIndex] * skill[wizardIndex];
            }

            // Adjust timings backward to maintain synchronization
            for (int wizardIndex = totalWizards - 1; wizardIndex > 0; wizardIndex--) {
                finishTime[wizardIndex - 1] = finishTime[wizardIndex]
                        - (long) mana[potionIndex] * skill[wizardIndex];
            }
        }

        // The total time is when the last wizard finishes the last potion
        return finishTime[totalWizards - 1];
    }
}
