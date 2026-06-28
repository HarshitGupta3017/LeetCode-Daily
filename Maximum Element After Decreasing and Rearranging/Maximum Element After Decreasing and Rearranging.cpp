// Solution for Maximum Element After Decreasing and Rearranging in CPP

class Solution {
public:
   int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

       // Sorting lets us process elements from smallest to largest.
       // Since we can rearrange freely, sorting is equivalent to choosing
       // the optimal order — we always want smaller values placed first
       // so they don't "waste" room that larger values could fill.
       sort(arr.begin(), arr.end());

       // The first element must be exactly 1 per the problem constraints.
       // We can only decrease values, never increase, so clamping to 1 is safe.
       arr[0] = 1;

       for (int i = 1; i < (int)arr.size(); i++) {
           // If arr[i] is already within 1 of its predecessor, keep it as-is —
           // reducing it further would only lower our final answer unnecessarily.
           // If the gap is too large, pull arr[i] down to arr[i-1] + 1 so the
           // adjacency constraint is satisfied while still climbing as high as possible.
           if (arr[i] - arr[i - 1] > 1)
               arr[i] = arr[i - 1] + 1;
       }

       // After the greedy pass, the last element is the maximum achievable value
       // because the sequence was built to climb by at most 1 at every step.
       return arr.back();
   }
};
