// Solution for Find X-Sum of All K-Long Subarrays II in CPP

class Solution {
public:

    // Helper function to remove a (frequency, value) pair from appropriate set
    void removeFromSet(const pair<int, int>& freqValPair, 
                       set<pair<int, int>>& topElements, 
                       set<pair<int, int>>& remainingElements, 
                       long long& currentSum) {
        
        // Case 1: Element exists in the top 'x' frequent elements
        if (topElements.count(freqValPair)) {
            currentSum -= 1LL * freqValPair.first * freqValPair.second;
            topElements.erase(freqValPair);

            // If topElements has fewer than x elements now, move one from remainingElements
            if (!remainingElements.empty()) {
                auto largestInRemaining = *remainingElements.rbegin(); // Most frequent or higher value
                currentSum += 1LL * largestInRemaining.first * largestInRemaining.second;
                remainingElements.erase(largestInRemaining);
                topElements.insert(largestInRemaining);
            }
        } 
        // Case 2: Element exists in remainingElements (not in top 'x')
        else {
            remainingElements.erase(freqValPair);
        }
    }

    // Helper function to insert a (frequency, value) pair into appropriate set
    void insertInSet(const pair<int, int>& freqValPair, 
                     set<pair<int, int>>& topElements, 
                     set<pair<int, int>>& remainingElements, 
                     long long& currentSum, int x) {
        
        // If topElements has space or the new pair is more frequent/larger
        if (topElements.size() < x || freqValPair > *topElements.begin()) {
            currentSum += 1LL * freqValPair.first * freqValPair.second;
            topElements.insert(freqValPair);

            // If size exceeds x, move the smallest from topElements to remainingElements
            if (topElements.size() > x) {
                auto smallestInTop = *topElements.begin();
                currentSum -= 1LL * smallestInTop.first * smallestInTop.second;
                topElements.erase(smallestInTop);
                remainingElements.insert(smallestInTop);
            }
        } 
        // Otherwise, insert into remainingElements
        else {
            remainingElements.insert(freqValPair);
        }
    }

    // Main function to find x-sum for all subarrays of length k
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> result;
        unordered_map<int, int> freqMap;  // Tracks frequency of each number
        int windowStart = 0;
        long long currentSum = 0;

        // 'topElements' stores top x frequent elements, 'remainingElements' stores others
        set<pair<int, int>> topElements, remainingElements;

        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            int currentNum = nums[windowEnd];

            // If number already exists, remove old frequency pair
            if (freqMap[currentNum] > 0) {
                removeFromSet({freqMap[currentNum], currentNum}, topElements, remainingElements, currentSum);
            }

            // Increment its frequency and re-insert with updated count
            freqMap[currentNum]++;
            insertInSet({freqMap[currentNum], currentNum}, topElements, remainingElements, currentSum, x);

            // Once window reaches size k, record x-sum and slide window
            if (windowEnd - windowStart + 1 == k) {
                result.push_back(currentSum);

                int outgoingNum = nums[windowStart];
                removeFromSet({freqMap[outgoingNum], outgoingNum}, topElements, remainingElements, currentSum);
                freqMap[outgoingNum]--;

                // If outgoingNum still exists, re-insert with updated frequency
                if (freqMap[outgoingNum] == 0) {
                    freqMap.erase(outgoingNum);
                } else {
                    insertInSet({freqMap[outgoingNum], outgoingNum}, topElements, remainingElements, currentSum, x);
                }
                windowStart++;
            }
        }
        return result;
    }
};
