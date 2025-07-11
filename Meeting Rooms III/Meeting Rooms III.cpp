// Solution for Meeting Rooms III in CPP

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Step 1: Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        int totalMeetings = meetings.size();

        // Step 2: Track how many times each room is used
        vector<int> roomUsageCount(n, 0);

        // Track when each room will be free (initially all are free at time 0)
        vector<long long> roomFreeTime(n, 0);

        for (const auto& meeting : meetings) {
            int startTime = meeting[0];
            int endTime = meeting[1];
            int duration = endTime - startTime;

            bool roomAssigned = false;
            long long earliestFinishTime = LLONG_MAX;
            int earliestRoom = 0;

            // Step 3: Try to assign this meeting to the earliest available room
            for (int room = 0; room < n; room++) {
                if (roomFreeTime[room] <= startTime) {
                    // Room is available, assign meeting here
                    roomFreeTime[room] = endTime;
                    roomUsageCount[room]++;
                    roomAssigned = true;
                    break;
                }

                // Track the room with the earliest availability (for delay scenario)
                if (roomFreeTime[room] < earliestFinishTime) {
                    earliestFinishTime = roomFreeTime[room];
                    earliestRoom = room;
                }
            }

            // Step 4: If no room was available, delay meeting in earliest free room
            if (!roomAssigned) {
                roomFreeTime[earliestRoom] += duration;
                roomUsageCount[earliestRoom]++;
            }
        }

        // Step 5: Find the room with the most meetings (return smallest index if tie)
        int resultRoom = 0;
        int maxMeetings = roomUsageCount[0];

        for (int room = 1; room < n; room++) {
            if (roomUsageCount[room] > maxMeetings) {
                maxMeetings = roomUsageCount[room];
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};
