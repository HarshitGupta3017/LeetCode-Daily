// Solution for Number of Unique XOR Triplets I in CPP

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        // With 1 or 2 elements, the only possible triplets reuse indices.
        // i=j=k=0 gives nums[0]^nums[0]^nums[0] = nums[0] → 1 unique value.
        // For n=2 we also get nums[0]^nums[1]^nums[1]=nums[0] and
        // nums[0]^nums[0]^nums[1]=nums[1], so exactly 2 unique values.
        if (n <= 2) return n;

        // For n >= 3, nums is a permutation of [1..n], so every pair (i,j) with
        // i < j is available, and nums[i] XOR nums[j] can produce any value in
        // [0..nextPowerOf2-1]. Choosing k=j then lets us XOR with any third
        // element, filling out the full range [0..2^ceil(log2(n+1)) - 1].
        // The count of reachable XOR values is therefore the smallest power of 2
        // that is strictly greater than n.
        int reachable = 1;
        while (reachable <= n)
            reachable *= 2;

        return reachable;
    }
};
