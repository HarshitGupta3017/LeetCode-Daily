// Solution for Apply Operations to Maximize Score in CPP

class Solution {
public:
    const int MOD = 1e9 + 7;
    using ll = long long;

    ll findPower(ll a, ll b) {
        if (b == 0) return 1;
        ll half = findPower(a, b / 2);
        ll result = (half * half) % MOD;
        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }
        return result;
    }

    vector<int> getPrimes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;
        for (int i = 2; i * i <= limit; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 2; i <= limit; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }

    vector<int> findPrimeScores(vector<int>& nums) {
        int n = nums.size();
        vector<int> primeScores(n, 0);
        int maxEle = *max_element(begin(nums), end(nums));
        vector<int> primes = getPrimes(maxEle);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int prime: primes) {
                if (prime * prime > num) break;
                if (num % prime != 0) continue;
                primeScores[i]++;
                while (num % prime == 0) num /= prime;
            }
            if (num > 1) primeScores[i]++;
        }
        return primeScores;
    }
    
    vector<int> findNextGreater(vector<int>& primeScores) {
        int n = primeScores.size();
        vector<int> nextGreater(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && primeScores[st.top()] <= primeScores[i]) {
                st.pop();
            }
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nextGreater;
    }
    
    vector<int> findPrevGreater(vector<int>& primeScores) {
        int n = primeScores.size();
        vector<int> prevGreater(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && primeScores[st.top()] < primeScores[i]) {
                st.pop();
            }
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prevGreater;
    }

    int maximumScore(vector<int>& nums, int k) {
        vector<int> primeScores = findPrimeScores(nums);
        vector<int> nextGreater = findNextGreater(primeScores);
        vector<int> prevGreater = findPrevGreater(primeScores);
        
        int n = nums.size();
        vector<ll> subarrays(n, 0);
        for (int i = 0; i < n; i++) {
            subarrays[i] = (ll)(nextGreater[i] - i) * (i - prevGreater[i]);
        }

        vector<pair<int, int>> sortedNums(n);
        for (int i = 0; i < n; i++) {
            sortedNums[i] = {nums[i], i};
        }
        sort(begin(sortedNums), end(sortedNums));

        ll score = 1;
        int idx = n - 1;
        while (k > 0) {
            auto [num, i] = sortedNums[idx--];
            ll ops = min((ll)k, subarrays[i]);
            score = (score * findPower(num, ops)) % MOD;
            k -= ops;
        }
        return score;
    }
};
