// Solution for Minimum Jumps to Reach End via Prime Teleportation in CPP

class Solution {
public:

    // Sieve of Eratosthenes to identify prime numbers
    void buildSieve(int maximumValue, vector<bool>& isPrime) {

        isPrime[0] = false;
        isPrime[1] = false;

        for (int number = 2; number * number <= maximumValue; number++) {

            if (isPrime[number]) {

                for (int multiple = number * number;
                     multiple <= maximumValue;
                     multiple += number) {

                    isPrime[multiple] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {

        int totalElements = nums.size();

        // Map value -> all indices containing that value
        unordered_map<int, vector<int>> valueToIndicesMap;

        int maximumValue = 0;

        for (int index = 0; index < totalElements; index++) {

            valueToIndicesMap[nums[index]].push_back(index);

            maximumValue = max(maximumValue, nums[index]);
        }

        // Build prime lookup table
        vector<bool> isPrime(maximumValue + 1, true);
        buildSieve(maximumValue, isPrime);

        // Standard BFS setup
        queue<int> bfsQueue;

        vector<bool> visited(totalElements, false);

        bfsQueue.push(0);
        visited[0] = true;

        // Prevent repeated processing of same prime teleportation
        unordered_set<int> processedPrimes;

        int minimumSteps = 0;

        while (!bfsQueue.empty()) {

            int currentLevelSize = bfsQueue.size();

            while (currentLevelSize--) {

                int currentIndex = bfsQueue.front();
                bfsQueue.pop();

                // Reached destination
                if (currentIndex == totalElements - 1)
                    return minimumSteps;

                // -----------------------------------
                // Adjacent Move: Left
                // -----------------------------------
                if (currentIndex - 1 >= 0 &&
                    !visited[currentIndex - 1]) {

                    bfsQueue.push(currentIndex - 1);
                    visited[currentIndex - 1] = true;
                }

                // -----------------------------------
                // Adjacent Move: Right
                // -----------------------------------
                if (currentIndex + 1 < totalElements &&
                    !visited[currentIndex + 1]) {

                    bfsQueue.push(currentIndex + 1);
                    visited[currentIndex + 1] = true;
                }

                int currentValue = nums[currentIndex];

                // Skip if current value is not prime
                // OR prime teleportation already processed
                if (!isPrime[currentValue] ||
                    processedPrimes.count(currentValue)) {

                    continue;
                }

                // -----------------------------------
                // Prime Teleportation
                // Jump to all indices having values
                // divisible by current prime
                // -----------------------------------
                for (int multiple = currentValue; multiple <= maximumValue;
                     multiple += currentValue) {

                    if (!valueToIndicesMap.count(multiple))
                        continue;

                    for (int nextIndex : valueToIndicesMap[multiple]) {

                        if (!visited[nextIndex]) {

                            bfsQueue.push(nextIndex);
                            visited[nextIndex] = true;
                        }
                    }
                }

                // Mark this prime as processed
                processedPrimes.insert(currentValue);
            }

            minimumSteps++;
        }

        return -1;
    }
};
