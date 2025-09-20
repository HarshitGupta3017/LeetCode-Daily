// Solution for Implement Router in JAVA

class Router {
    private Queue<String> fifoQueue;                          // FIFO queue for insertion order
    private Map<String, int[]> packetMap;                     // key → [source, destination, timestamp]
    private Map<Integer, List<Integer>> destTimestamps;       // destination → sorted timestamps
    private int memoryLimit;

    public Router(int memoryLimit) {
        this.memoryLimit = memoryLimit;
        this.fifoQueue = new LinkedList<>();
        this.packetMap = new HashMap<>();
        this.destTimestamps = new HashMap<>();
    }

    // Helper: build unique key for a packet
    private String makeKey(int source, int destination, int timestamp) {
        return source + "_" + destination + "_" + timestamp;
    }

    // Add a new packet to the router
    public boolean addPacket(int source, int destination, int timestamp) {
        String key = makeKey(source, destination, timestamp);

        // Duplicate check
        if (packetMap.containsKey(key)) {
            return false;
        }

        // Evict oldest if memory full
        if (fifoQueue.size() >= memoryLimit) {
            forwardPacket();
        }

        // Store new packet
        fifoQueue.offer(key);
        packetMap.put(key, new int[]{source, destination, timestamp});

        destTimestamps.putIfAbsent(destination, new ArrayList<>());
        destTimestamps.get(destination).add(timestamp);

        return true;
    }

    // Forward oldest packet
    public int[] forwardPacket() {
        if (fifoQueue.isEmpty()) {
            return new int[]{}; // empty
        }

        String key = fifoQueue.poll();
        int[] packet = packetMap.remove(key);

        int destination = packet[1];
        List<Integer> times = destTimestamps.get(destination);
        if (!times.isEmpty()) {
            times.remove(0);  // remove earliest timestamp
        }
        if (times.isEmpty()) {
            destTimestamps.remove(destination);
        }

        return packet;
    }

    // Get count of packets for destination in [startTime, endTime]
    public int getCount(int destination, int startTime, int endTime) {
        if (!destTimestamps.containsKey(destination)) {
            return 0;
        }

        List<Integer> times = destTimestamps.get(destination);

        int left = lowerBound(times, startTime);
        int right = upperBound(times, endTime);

        return right - left;
    }

    // Custom binary search lower_bound
    private int lowerBound(List<Integer> list, int target) {
        int low = 0, high = list.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (list.get(mid) < target) low = mid + 1;
            else high = mid;
        }
        return low;
    }

    // Custom binary search upper_bound
    private int upperBound(List<Integer> list, int target) {
        int low = 0, high = list.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (list.get(mid) <= target) low = mid + 1;
            else high = mid;
        }
        return low;
    }
}
