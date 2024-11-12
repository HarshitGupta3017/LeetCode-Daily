class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // in this question we just need to compare each price with the query q and then if the 
        // price is less than or equal to query we need to store the beauty and at last return the max
        // beauty we can check using 2 for loops but the time complextiy will be high then
        // we can sort the items and use binary search for finding the point at which item is equal or less
        // than the query q but then till that point from start we need to find highest beauty 
        // for handling max beauty we can store them at each point at start so that when we get the point
        // of query q i.e. the item which is equal or less than it we can just return its beauty
        int n = items.size();
        // [1,2],[3,2],[2,4],[5,6],[3,5]
        sort(items.begin(), items.end());
        // after sorting it becomes
        // [1,2],[2,4],[3,2],[3,5],[5,6]
        int maxBeauty = items[0][1];
        // it will store max beauty till that item in each element like
        // now in this for loop it will store max beauty as 
        // [1,2],[2,4],[3,4],[3,5],[5,6] like this max beauty till that item from start
        for (int i = 1; i < n; i++) {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }
        vector<int> res;
        // now simple binary search on each query
        for (const int& q: queries) {
            // it is a function that uses binary search internally
            // it will return a item which is just greater than the query q
            auto it = upper_bound(items.begin(), items.end(), vector<int>{q, INT_MAX});
            // vector<int>{q, INT_MAX} - y we passed this??
            // cuz items is a 2D array and we need find item greater than q 
            // and INT_MAX for finding highest beauty
            // now it will return a item just greater than q so we will take its prev element
            res.push_back(it == items.begin() ? 0 : prev(it)->at(1));
            // if it is still at begin so return 0 as question stated otherwise take prev element and 
            // access beauty using "at"
        }
        return res;
    }
};
