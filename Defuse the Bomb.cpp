class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // easy question?
        // we can see there is a limit i.e. till which we need to calculate sum
        // can we use sliding window here then???
        // compute for first one and then shift window for other
        // lets try
        int n = code.size();
        vector<int> res(n, 0);
        if (k == 0) return res;
        // window of size k 
        // but if k is negative we will start from last 2 elements 
        int start = 1, end = k;
        if (k < 0) {
            start = n - (abs(k));
            end = n - 1;
            // eg - code = [2,4,9,3], k = -2
            // here start will be 4 - 2 = 2, end = 3
            // i.e. last 2 elements as in negative we need to take previous ones and array is circular
            // if we start from last 2 then we can simply shift window by doing start++, end++
            // and removing start sum from total one and adding end sum to it
        }
        int sum = 0;
        // computed for first one
        for (int i = start; i <= end; i++) {
            sum += code[i % n];
        }
        // now window shifts
        for (int i = 0; i < n; i++) {
            res[i] = sum;
            sum -= code[start % n];
            // removing start from sum and incrementing start
            // also incrementing end early to add the next element
            start++, end++;
            sum += code[end % n];
        }
        return res;
    }
};
