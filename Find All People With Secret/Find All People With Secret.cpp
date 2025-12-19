// Solution for Find All People With Secret in CPP

class Solution {
public:
    // Pair format: {time, person}
    using TimePersonPair = pair<int, int>;

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        // Adjacency list:
        // key   -> person
        // value -> list of {neighborPerson, meetingTime}
        unordered_map<int, vector<TimePersonPair>> adjacencyList;

        // Build the graph from meetings
        for (const auto& meeting : meetings) {
            int personA = meeting[0];
            int personB = meeting[1];
            int meetingTime = meeting[2];

            // Since meetings are bidirectional, add edges both ways
            adjacencyList[personA].push_back({personB, meetingTime});
            adjacencyList[personB].push_back({personA, meetingTime});
        }

        // Min-heap priority queue to process people in increasing order of time
        // Each entry is {timeWhenSecretKnown, person}
        priority_queue<
            TimePersonPair,
            vector<TimePersonPair>,
            greater<TimePersonPair>
        > minHeap;

        // Person 0 has the secret at time 0
        minHeap.push({0, 0});

        // firstPerson also receives the secret at time 0
        minHeap.push({0, firstPerson});

        // Tracks whether a person has already been finalized as knowing the secret
        vector<bool> hasSecret(n, false);

        // Process the priority queue (Dijkstra-like traversal)
        while (!minHeap.empty()) {

            // Get the person who knows the secret at the earliest time
            auto [currentTime, currentPerson] = minHeap.top();
            minHeap.pop();

            // If we already processed this person, skip
            if (hasSecret[currentPerson]) {
                continue;
            }

            // Mark this person as having the secret
            hasSecret[currentPerson] = true;

            // Explore all meetings involving this person
            for (const auto& neighbor : adjacencyList[currentPerson]) {

                int nextPerson = neighbor.first;
                int meetingTime = neighbor.second;

                // The secret can be shared only if:
                // 1. The meeting happens at or after the time currentPerson knows the secret
                // 2. The next person has not already received the secret
                if (meetingTime >= currentTime && !hasSecret[nextPerson]) {
                    minHeap.push({meetingTime, nextPerson});
                }
            }
        }

        // Collect all people who ended up knowing the secret
        vector<int> peopleWithSecret;
        for (int person = 0; person < n; person++) {
            if (hasSecret[person]) {
                peopleWithSecret.push_back(person);
            }
        }

        return peopleWithSecret;
    }
};
