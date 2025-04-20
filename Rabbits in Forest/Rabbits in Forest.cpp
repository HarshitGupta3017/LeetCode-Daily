// Solution for Rabbits in Forest in CPP

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        int result = 0;
        for (int ans : answers) {
            count[ans]++;
        }
        for (auto& [k, freq] : count) {
            int groupSize = k + 1;
            int groups = ceil((double) freq / groupSize);
            result += groups * groupSize;
        }
        return result;
    }
};
