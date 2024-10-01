class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (const auto& num: arr) {
            mp[(num % k + k) % k]++;
        }
        if (mp[0] % 2 != 0) return false;
        for (int rem = 1; rem <= k / 2; rem++) {
            int left = k - rem;
            if (mp[rem] != mp[left]) return false;
        }
        return true;
    }
};
