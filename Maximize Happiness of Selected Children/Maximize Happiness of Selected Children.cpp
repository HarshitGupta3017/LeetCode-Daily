// Solution for Maximize Happiness of Selected Children in CPP

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();

        // Sort happiness in descending order so we always pick the child with highest happiness
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long totalHappiness = 0;

        // Select k children
        for (int turn = 0; turn < k; turn++) {
            // Happiness decreases by 1 for each previously selected child
            long long currentHappiness = max(happiness[turn] - turn, 0);
            totalHappiness += currentHappiness;
        }

        return totalHappiness;
    }
};
