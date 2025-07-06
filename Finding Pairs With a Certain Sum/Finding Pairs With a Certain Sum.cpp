// Solution for Finding Pairs With a Certain Sum in CPP

class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> freqMap;

    // Constructor to initialize with two arrays
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;

        // Build frequency map for nums2
        for (const int& num : nums2) {
            freqMap[num]++;
        }
    }

    // Adds val to nums2[index] and updates frequency map accordingly
    void add(int index, int val) {
        int oldVal = nums2[index];
        freqMap[oldVal]--;         // Decrement count of old value
        nums2[index] += val;
        int newVal = nums2[index];
        freqMap[newVal]++;         // Increment count of new value
    }

    // Counts the number of valid pairs (i, j) such that nums1[i] + nums2[j] == tot
    int count(int tot) {
        int totalPairs = 0;
        for (const int& num1 : nums1) {
            int required = tot - num1;
            totalPairs += freqMap[required];  // Use precomputed frequency map
        }
        return totalPairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
