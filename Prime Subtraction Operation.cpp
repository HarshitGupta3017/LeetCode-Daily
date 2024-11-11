class Solution {
public:

    void SOE(vector<bool>& isPrime) {
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < 1000; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < 1000; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        // simple question we just need to maintain strictly increasing order in an array
        // and for that if one number is larger than other we can perform one operation as given
        // we can choose a prime number smaller than that number and decrement from it such that 
        // it becomes smaller than other
        int n = nums.size();
        vector<bool> isPrime(1000, true);
        // lets use sieve of eratosthenes here to fill this array that will tell us about if a number
        // is prime or not
        SOE(isPrime);
        // let's start from back as we don't need to keep track of elements from back so we can do 
        // one by one
        // eg - [4,9,6,10]
        for (int i = n - 2; i >= 0; i--) {
            // now 6 < 10 so its fine continue
            if (nums[i] < nums[i + 1]) continue;
            // else if its larger or equal we need to decrease a prime number
            // starting from 2 and till that number 
            for (int p = 2; p < nums[i]; p++) {
                // if its not prime continue
                if (!isPrime[p]) continue;
                // else check if after decreasing its becoming less
                if (nums[i] - p < nums[i + 1]) {
                    nums[i] -= p;
                    break;
                }
            }
            // even after that if the number isn't less than the next one return false
            if (nums[i] >= nums[i + 1]) return false; // as it can't be made increasing array 
        }
        // after all process if its iterated entirely
        return true;
    }
};
