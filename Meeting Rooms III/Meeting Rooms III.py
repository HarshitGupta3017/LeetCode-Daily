# Solution for Meeting Rooms III in PY

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        room_free = [0] * n
        room_usage = [0] * n

        for start, end in meetings:
            duration = end - start
            assigned = False
            earliest = float('inf')
            earliest_room = 0

            for i in range(n):
                if room_free[i] <= start:
                    room_free[i] = end
                    room_usage[i] += 1
                    assigned = True
                    break
                if room_free[i] < earliest:
                    earliest = room_free[i]
                    earliest_room = i

            if not assigned:
                room_free[earliest_room] += duration
                room_usage[earliest_room] += 1

        max_room = 0
        for i in range(1, n):
            if room_usage[i] > room_usage[max_room]:
                max_room = i
        return max_room
