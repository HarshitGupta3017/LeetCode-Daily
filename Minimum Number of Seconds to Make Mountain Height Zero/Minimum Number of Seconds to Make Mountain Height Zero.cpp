// Solution for Minimum Number of Seconds to Make Mountain Height Zero in CPP

class Solution {
public:

    using ll = long long;

    /*
        This function checks whether it is possible to reduce
        the mountain height to 0 within 'timeLimit' seconds.
    */
    bool canReduceMountain(ll timeLimit, int mountainHeight, vector<int>& workerTimes) {

        /*
            totalHeightReduced keeps track of how much total
            height all workers can remove within 'timeLimit'.
        */
        ll totalHeightReduced = 0;

        for (const int& workerTime : workerTimes) {

            /*
                Time required for a worker to reduce height x:

                workerTime * (1 + 2 + 3 + ... + x)

                Sum of first x natural numbers:
                x(x + 1) / 2

                So total time required:

                workerTime * x(x + 1) / 2 <= timeLimit

                Rearranging:

                x(x + 1) <= (2 * timeLimit) / workerTime

                Solve quadratic equation:
                x^2 + x - (2*timeLimit/workerTime) <= 0

                Using quadratic formula:

                x = (-1 + sqrt(1 + 8*timeLimit/workerTime)) / 2

                The formula below is an equivalent simplified form.
            */

            ll maxHeightByWorker = (ll)(sqrt(2.0 * timeLimit / workerTime + 0.25) - 0.5);

            totalHeightReduced += maxHeightByWorker;

            /*
                Early stopping if we already reduced enough height.
            */
            if (totalHeightReduced >= mountainHeight)
                return true;
        }

        return totalHeightReduced >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        /*
            Binary search range:

            Minimum possible time = 1 second

            Maximum possible time:
            slowest worker doing all work alone
        */
        ll left = 1;

        ll slowestWorkerTime = *max_element(workerTimes.begin(), workerTimes.end());

        /*
            Worst case:
            slowest worker removes entire mountain.
        */
        ll right = slowestWorkerTime * (ll)mountainHeight * (mountainHeight + 1) / 2;

        ll minimumTime = 0;

        /*
            Binary search for minimum time
            where mountain height can be reduced to zero.
        */
        while (left <= right) {

            ll midTime = left + (right - left) / 2;

            if (canReduceMountain(midTime, mountainHeight, workerTimes)) {

                /*
                    If it is possible within midTime,
                    try to find an even smaller time.
                */
                minimumTime = midTime;
                right = midTime - 1;
            }
            else {

                /*
                    If not possible, we need more time.
                */
                left = midTime + 1;
            }
        }

        return minimumTime;
    }
};
