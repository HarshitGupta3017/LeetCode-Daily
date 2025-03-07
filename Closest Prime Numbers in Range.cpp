class Solution {
public:

    vector<bool> sieveOfErastothenes(int n) {
        vector<bool> temp(n + 1, true);
        temp[0] = temp[1] = false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (temp[i] == true) {
                for (int j = 2; i * j <= n; j++) {
                    temp[i * j] = false;
                }
            }
        }
        return temp;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime = sieveOfErastothenes(right);
        vector<int> primes;
        vector<int> result = {-1, -1};
        for (int num = left; num <= right; num++) {
            if (isPrime[num]) primes.push_back(num);
        }
        int minval = INT_MAX;
        for (int i = 1; i < primes.size(); i++) {
            if (primes[i] - primes[i - 1] < minval) {
                minval = primes[i] - primes[i - 1];
                result[0] = primes[i - 1];
                result[1] = primes[i];
            }
        }
        return result;
    }
};
