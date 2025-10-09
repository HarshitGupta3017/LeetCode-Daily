// Solution for Find the Minimum Amount of Time to Brew Potions in CPP

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int totalWizards = skill.size();   // Number of wizards
        int totalPotions = mana.size();    // Number of potions

        // finishTime[i] → time when the i-th wizard finishes processing the current potion
        vector<long long> finishTime(totalWizards, 0);

        // Process each potion sequentially
        for (int potionIndex = 0; potionIndex < totalPotions; potionIndex++) {

            // Wizard 0 always starts first; add time taken by wizard 0 for this potion
            finishTime[0] += 1LL * mana[potionIndex] * skill[0];

            // Process this potion through all wizards sequentially
            for (int wizardIndex = 1; wizardIndex < totalWizards; wizardIndex++) {

                // Each wizard must start only after:
                // - they have finished their previous potion, AND
                // - the previous wizard has finished this potion
                finishTime[wizardIndex] = max(finishTime[wizardIndex], 
                finishTime[wizardIndex  - 1]) + 1LL * mana[potionIndex] * skill[wizardIndex];
            }

            // Adjust the finish times backward to maintain synchronization
            // This ensures the previous wizard’s timing reflects potion flow properly
            for (int wizardIndex = totalWizards - 1; wizardIndex > 0; wizardIndex--) {
                finishTime[wizardIndex - 1] = finishTime[wizardIndex] - 
                1LL * mana[potionIndex] * skill[wizardIndex];
            }
        }

        // The total time required is when the last wizard finishes the last potion
        return finishTime[totalWizards - 1];
    }
};
