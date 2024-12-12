class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // easy question
        // pick largest from the array and perform the floor and sqrt operation on that and
        // push it back 
        // perform this k times
        // best data structure for this is max heap right?? storing elements in descending order
        priority_queue<long long> pq(gifts.begin(), gifts.end());
        long long res = 0;
        while (k--) {
            // as asked in question
            long long temp = floor(sqrt(pq.top()));
            pq.pop();
            pq.push(temp);
        }
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
