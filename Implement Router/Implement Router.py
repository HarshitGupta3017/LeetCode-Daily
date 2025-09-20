# Solution for Implement Router in PY

class Router:
    def __init__(self, memoryLimit: int):
        self.fifoQueue = deque()                     # FIFO queue for insertion order
        self.packetMap = {}                          # key → [source, destination, timestamp]
        self.destTimestamps = defaultdict(list)      # destination → sorted list of timestamps
        self.memoryLimit = memoryLimit

    # Helper: build unique key for a packet
    def makeKey(self, source: int, destination: int, timestamp: int) -> str:
        return f"{source}_{destination}_{timestamp}"

    # Add a new packet
    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        key = self.makeKey(source, destination, timestamp)

        # Duplicate check
        if key in self.packetMap:
            return False

        # Evict oldest if memory full
        if len(self.fifoQueue) >= self.memoryLimit:
            self.forwardPacket()

        # Store new packet
        self.fifoQueue.append(key)
        self.packetMap[key] = [source, destination, timestamp]
        bisect.insort(self.destTimestamps[destination], timestamp)

        return True

    # Forward oldest packet
    def forwardPacket(self) -> list[int]:
        if not self.fifoQueue:
            return []

        key = self.fifoQueue.popleft()
        packet = self.packetMap.pop(key)

        dest = packet[1]
        # Remove earliest timestamp for this destination
        times = self.destTimestamps[dest]
        times.pop(0)   # since we maintain sorted order with bisect.insort
        if not times:
            del self.destTimestamps[dest]

        return packet

    # Get count of packets for destination in [startTime, endTime]
    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        if destination not in self.destTimestamps:
            return 0

        times = self.destTimestamps[destination]
        left = bisect.bisect_left(times, startTime)
        right = bisect.bisect_right(times, endTime)

        return right - left
