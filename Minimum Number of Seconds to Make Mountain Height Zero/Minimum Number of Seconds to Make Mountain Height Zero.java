// Solution for Minimum Number of Seconds to Make Mountain Height Zero in JAVA

class Solution {

    /*
        This function checks whether it is possible to reduce
        the mountain height to 0 within 'timeLimit' seconds.
    */
    private boolean canReduceMountain(long timeLimit, int mountainHeight, int[] workerTimes) {

        long totalHeightReduced = 0;

        for (int workerTime : workerTimes) {

            /*
                Maximum height this worker can reduce within timeLimit.

                Using derived formula:
                x = sqrt(2*timeLimit/workerTime + 0.25) - 0.5
            */
            long maxHeightByWorker =
                (long)(Math.sqrt(2.0 * timeLimit / workerTime + 0.25) - 0.5);

            totalHeightReduced += maxHeightByWorker;

            // Early stopping if we already reduced enough
            if (totalHeightReduced >= mountainHeight)
                return true;
        }

        return totalHeightReduced >= mountainHeight;
    }

    public long minNumberOfSeconds(int mountainHeight, int[] workerTimes) {

        long left = 1;

        int slowestWorkerTime = 0;
        for (int t : workerTimes)
            slowestWorkerTime = Math.max(slowestWorkerTime, t);

        /*
            Worst case:
            slowest worker removes the entire mountain
        */
        long right =
            (long) slowestWorkerTime * mountainHeight * (mountainHeight + 1) / 2;

        long minimumTime = 0;

        while (left <= right) {

            long midTime = left + (right - left) / 2;

            if (canReduceMountain(midTime, mountainHeight, workerTimes)) {

                minimumTime = midTime;
                right = midTime - 1;
            }
            else {
                left = midTime + 1;
            }
        }

        return minimumTime;
    }
}
