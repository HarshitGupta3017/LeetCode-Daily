# Solution for Find All People With Secret in PY

from typing import List
import heapq
from collections import defaultdict

class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:

        # Adjacency list:
        # key   -> person
        # value -> list of (neighborPerson, meetingTime)
        adjacency_list = defaultdict(list)

        # Build the graph from meetings
        for person_a, person_b, meeting_time in meetings:
            # Since meetings are bidirectional, add edges both ways
            adjacency_list[person_a].append((person_b, meeting_time))
            adjacency_list[person_b].append((person_a, meeting_time))

        # Min-heap priority queue to process people in increasing order of time
        # Each entry is (timeWhenSecretKnown, person)
        min_heap = []

        # Person 0 has the secret at time 0
        heapq.heappush(min_heap, (0, 0))

        # firstPerson also receives the secret at time 0
        heapq.heappush(min_heap, (0, firstPerson))

        # Tracks whether a person has already been finalized as knowing the secret
        has_secret = [False] * n

        # Process the priority queue (Dijkstra-like traversal)
        while min_heap:
            # Get the person who knows the secret at the earliest time
            current_time, current_person = heapq.heappop(min_heap)

            # If we already processed this person, skip
            if has_secret[current_person]:
                continue

            # Mark this person as having the secret
            has_secret[current_person] = True

            # Explore all meetings involving this person
            for next_person, meeting_time in adjacency_list[current_person]:

                # The secret can be shared only if:
                # 1. The meeting happens at or after the time current_person knows the secret
                # 2. The next person has not already received the secret
                if meeting_time >= current_time and not has_secret[next_person]:
                    heapq.heappush(min_heap, (meeting_time, next_person))

        # Collect all people who ended up knowing the secret
        people_with_secret = []
        for person in range(n):
            if has_secret[person]:
                people_with_secret.append(person)

        return people_with_secret
