// Solution for Earliest Finish Time for Land and Water Rides I in CPP

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int landRideCount = landStartTime.size();
        int waterRideCount = waterStartTime.size();

        int earliestCompletionTime = INT_MAX;

        for (int landRide = 0; landRide < landRideCount; landRide++) {

            // Time when the selected land ride finishes
            // if boarded as soon as it becomes available.
            int landFinishTime = landStartTime[landRide] + landDuration[landRide];

            for (int waterRide = 0; waterRide < waterRideCount; waterRide++) {

                // Time when the selected water ride finishes
                // if boarded as soon as it becomes available.
                int waterFinishTime = waterStartTime[waterRide] + waterDuration[waterRide];

                /*
                    Order 1: Land Ride -> Water Ride

                    After completing the land ride, the tourist can
                    immediately board the water ride if it is already open.
                    Otherwise, they must wait until the water ride opens.
                */
                int finishLandThenWater = max(landFinishTime, waterStartTime[waterRide]) + waterDuration[waterRide];

                /*
                    Order 2: Water Ride -> Land Ride

                    Symmetric calculation for taking the water ride first.
                */
                int finishWaterThenLand = max(waterFinishTime, landStartTime[landRide]) + landDuration[landRide];

                // Keep track of the best completion time among
                // all ride pairs and both possible orders.
                earliestCompletionTime = min({earliestCompletionTime, finishLandThenWater, finishWaterThenLand});
            }
        }

        return earliestCompletionTime;
    }
};
