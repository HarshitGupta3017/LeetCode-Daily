// Solution for Minimum Operations to Equalize Binary String in CPP

class Solution {
public:
    int minOperations(string s, int k) {

        int length = s.size();

        // Step 1: Count how many zeros initially exist.
        int initialZeroCount = count(s.begin(), s.end(), '0');

        // If already all ones → no operation needed.
        if (initialZeroCount == 0)
            return 0;

        /*
            visitedOperations[z] =
            minimum operations needed to reach zeroCount = z.
            -1 means unvisited.
        */
        vector<int> visitedOperations(length + 1, -1);

        /*
            Because parity is restricted:
            newZ ≡ z + k (mod 2)

            We store unvisited zero counts separately
            based on parity for fast access.
        */
        set<int> unvisitedEvenZeroCounts;
        set<int> unvisitedOddZeroCounts;

        for (int zeroCount = 0; zeroCount <= length; zeroCount++) {
            if (zeroCount % 2 == 0)
                unvisitedEvenZeroCounts.insert(zeroCount);
            else
                unvisitedOddZeroCounts.insert(zeroCount);
        }

        // BFS queue
        queue<int> bfsQueue;

        bfsQueue.push(initialZeroCount);
        visitedOperations[initialZeroCount] = 0;

        // Remove from unvisited since we are visiting it
        if (initialZeroCount % 2 == 0)
            unvisitedEvenZeroCounts.erase(initialZeroCount);
        else
            unvisitedOddZeroCounts.erase(initialZeroCount);

        /*
            BFS begins:
            Each node = current zero count
        */
        while (!bfsQueue.empty()) {

            int currentZeroCount = bfsQueue.front();
            bfsQueue.pop();

            /*
                We compute valid range of f:

                f = number of zeros flipped.

                Must satisfy:
                0 ≤ f ≤ currentZeroCount
                0 ≤ k - f ≤ length - currentZeroCount
            */

            int minimumZerosFlipped = max(0, k - (length - currentZeroCount));

            int maximumZerosFlipped = min(k, currentZeroCount);

            /*
                Using formula:
                newZeroCount = currentZeroCount + k - 2f

                When f is maximum → newZeroCount is minimum.
                When f is minimum → newZeroCount is maximum.
            */

            int minimumNewZeroCount = currentZeroCount + k - 2 * maximumZerosFlipped;

            int maximumNewZeroCount = currentZeroCount + k - 2 * minimumZerosFlipped;

            /*
                Because parity is fixed by:
                newZ ≡ currentZeroCount + k (mod 2)

                We only check that parity set.
            */
            bool nextParityIsEven = (minimumNewZeroCount % 2 == 0);

            set<int>& candidateSet = nextParityIsEven ?
                unvisitedEvenZeroCounts : unvisitedOddZeroCounts;

            /*
                We now iterate over all unvisited zeroCounts
                within [minimumNewZeroCount, maximumNewZeroCount].
            */

            auto iterator = candidateSet.lower_bound(minimumNewZeroCount);

            while (iterator != candidateSet.end() && *iterator <= maximumNewZeroCount) {

                int nextZeroCount = *iterator;

                visitedOperations[nextZeroCount] = visitedOperations[currentZeroCount] + 1;

                // If we reached 0 → success.
                if (nextZeroCount == 0)
                    return visitedOperations[nextZeroCount];

                bfsQueue.push(nextZeroCount);

                // Remove so we don't process again.
                iterator = candidateSet.erase(iterator);
            }
        }

        // If BFS ends and never reached 0
        return -1;
    }
};
