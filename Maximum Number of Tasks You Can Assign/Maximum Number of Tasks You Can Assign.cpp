// Solution for Maximum Number of Tasks You Can Assign in CPP

class Solution {
public:

    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid) {
        int pillsUsed = 0;
        multiset<int> st(begin(workers), begin(workers) + mid);
        for (int i = mid - 1; i >= 0; i--) {
            int req = tasks[i];
            auto it = prev(st.end());
            int strongestWorker = *it;
            if (strongestWorker >= req) {
                st.erase(it);
            } else if (pillsUsed >= pills) {
                return false;
            } else {
                auto weakestWorkerIt = st.lower_bound(req - strength);
                if (weakestWorkerIt == st.end()) {
                    return false;
                }
                st.erase(weakestWorkerIt);
                pillsUsed++;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size();
        int n = workers.size();
        int l = 0, r = min(m, n);
        int res = 0;
        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers), greater<int>());
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(tasks, workers, pills, strength, mid)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
