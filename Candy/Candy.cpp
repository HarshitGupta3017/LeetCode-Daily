// Solution for Candy in CPP

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();  // Total number of children

        int totalCandies = n;    // Each child gets at least 1 candy
        int index = 1;           // Start from the second child

        while (index < n) {
            // If ratings are equal, no extra candy is needed
            if (ratings[index] == ratings[index - 1]) {
                index++;
                continue;
            }

            // Handle increasing ratings (uphill pattern)
            int uphillLength = 0;
            while (index < n && ratings[index] > ratings[index - 1]) {
                uphillLength++;
                totalCandies += uphillLength;  // Give more candies than previous
                index++;
            }

            // Handle decreasing ratings (downhill pattern)
            int downhillLength = 0;
            while (index < n && ratings[index] < ratings[index - 1]) {
                downhillLength++;
                totalCandies += downhillLength;  // Give more candies than next
                index++;
            }

            // Subtract the overlap: the peak child was counted in both uphill and downhill
            totalCandies -= min(uphillLength, downhillLength);
        }

        return totalCandies;
    }
};
