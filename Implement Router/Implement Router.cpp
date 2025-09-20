// Solution for Implement Router in CPP

class Router {
public:
    // FIFO queue to maintain insertion order of packets
    queue<string> fifoQueue;

    // Maps packet key → [source, destination, timestamp]
    unordered_map<string, vector<int>> packetMap;

    // Maps destination → sorted timestamps of packets still in memory
    unordered_map<int, vector<int>> destTimestamps;

    int memoryLimit; // Maximum number of packets router can store

    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    // Helper: build unique key for a packet
    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "_" + to_string(destination) + "_" + to_string(timestamp);
    }

    // Add a new packet to the router
    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);

        // Duplicate check
        if (packetMap.count(key)) {
            return false;
        }

        // Evict oldest packet if memory is full
        if ((int)fifoQueue.size() >= memoryLimit) {
            forwardPacket();
        }

        // Store new packet
        fifoQueue.push(key);
        packetMap[key] = {source, destination, timestamp};
        destTimestamps[destination].push_back(timestamp);

        return true;
    }

    // Forward the next packet in FIFO order
    vector<int> forwardPacket() {
        if (fifoQueue.empty()) {
            return {};
        }

        string key = fifoQueue.front();
        fifoQueue.pop();

        vector<int> packet = packetMap[key];
        packetMap.erase(key);

        int destination = packet[1];
        // Remove earliest timestamp for this destination
        destTimestamps[destination].erase(destTimestamps[destination].begin());

        return packet;
    }

    // Get count of packets for a destination within [startTime, endTime]
    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamps.find(destination);
        if (it == destTimestamps.end() || it->second.empty()) {
            return 0;
        }

        const vector<int>& times = it->second;

        // Binary search for range
        int left = lower_bound(times.begin(), times.end(), startTime) - times.begin();
        int right = upper_bound(times.begin(), times.end(), endTime) - times.begin();

        return right - left;
    }
};

/**
 * Example usage:
 * Router* router = new Router(memoryLimit);
 * bool added = router->addPacket(source, destination, timestamp);
 * vector<int> forwarded = router->forwardPacket();
 * int count = router->getCount(destination, startTime, endTime);
 */
