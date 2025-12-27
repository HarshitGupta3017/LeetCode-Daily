// Solution for Meeting Rooms III in CPP

--------------------------------------------- BRUTEFORCE ---------------------------------------------

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

--------------------------------------------- BRUTEFORCE ---------------------------------------------

--------------------------------------------- OPTIMAL ---------------------------------------------

class Solution {
public:
    // (endTime, roomNumber)
    using P = pair<long long, int>;

    int mostBooked(int n, vector<vector<int>>& meetings) {

        // Sort meetings by their start time (guaranteed unique starts)
        sort(meetings.begin(), meetings.end());

        // Count how many meetings each room hosts
        vector<int> roomsUsedCount(n, 0);

        // Min-heap of rooms currently in use:
        // Top gives the room that becomes free the earliest
        priority_queue<P, vector<P>, greater<P>> usedRooms;

        // Min-heap of available room numbers:
        // Always assign the smallest indexed free room
        priority_queue<int, vector<int>, greater<int>> availableRooms;

        // Initially, all rooms are free
        for (int room = 0; room < n; room++) {
            availableRooms.push(room);
        }

        // Process each meeting in chronological order
        for (const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            int duration = end - start;

            // Free all rooms whose meetings ended before or at current start time
            while (!usedRooms.empty() && usedRooms.top().first <= start) {
                int freedRoom = usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(freedRoom);
            }

            // Case 1: A room is available → assign immediately
            if (!availableRooms.empty()) {
                int room = availableRooms.top();
                availableRooms.pop();

                // Push this room as occupied until 'end'
                usedRooms.push({end, room});
                roomsUsedCount[room]++;
            }
            // Case 2: No room is available → delay the meeting
            else {
                // Pick the room that becomes free the earliest
                auto [earliestEnd, room] = usedRooms.top();
                usedRooms.pop();

                // Delay meeting but keep its duration same
                usedRooms.push({earliestEnd + duration, room});
                roomsUsedCount[room]++;
            }
        }

        // Find the room with the maximum number of meetings
        int resultRoom = 0;
        for (int room = 1; room < n; room++) {
            if (roomsUsedCount[room] > roomsUsedCount[resultRoom]) {
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};

--------------------------------------------- OPTIMAL ---------------------------------------------

