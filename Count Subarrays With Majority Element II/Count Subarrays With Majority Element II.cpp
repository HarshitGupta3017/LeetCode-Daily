// Solution for Count Subarrays With Majority Element II in CPP

class Solution {
public:
   long long countMajoritySubarrays(vector<int>& nums, int target) {

       // Transform the array into a +1/-1 sequence:
       // +1 for each occurrence of target, -1 for everything else.
       // A subarray has target as its majority element iff the sum of its
       // transformed values is strictly positive (more +1s than -1s).
       // Equivalently, prefixSum[right+1] - prefixSum[left] > 0,
       // i.e. prefixSum[right+1] > prefixSum[left].
       // So we need to count pairs (left, right) where the prefix sum strictly increased.

       // prefixFreq[s] = number of times prefix sum s has been seen so far.
       unordered_map<int, int> prefixFreq;
       prefixFreq[0] = 1;  // empty prefix has sum 0

       int prefixSum = 0;

       // validLeftCount = number of previously seen prefix sums that are
       // strictly less than the current prefix sum, i.e. starting points
       // from which target is already the majority up to the current index.
       int validLeftCount = 0;

       long long result = 0;

       for (int num : nums) {
           if (num == target) {
               // Prefix sum is about to increase by 1.
               // All left endpoints with prefix sum == current prefixSum become valid
               // (their subarrays will have a strictly positive transformed sum after this step).
               validLeftCount += prefixFreq[prefixSum];
               prefixSum++;
           } else {
               // Prefix sum is about to decrease by 1.
               // Left endpoints with prefix sum == prefixSum - 1 were previously valid
               // but will no longer be after this step (the gap shrinks to 0).
               prefixSum--;
               validLeftCount -= prefixFreq[prefixSum];
           }

           // Record this new prefix sum so future right endpoints can count it.
           prefixFreq[prefixSum]++;

           // Every previously valid left endpoint pairs with the current right endpoint
           // to form a subarray where target is the majority element.
           result += validLeftCount;
       }

       return result;
   }
};
