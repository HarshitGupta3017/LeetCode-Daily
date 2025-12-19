// Solution for Find All People With Secret in JAVA

import java.util.*;

class Solution {

    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {

        // Adjacency list:
        // key   -> person
        // value -> list of {neighborPerson, meetingTime}
        Map<Integer, List<int[]>> adjacencyList = new HashMap<>();

        // Build the graph from meetings
        for (int[] meeting : meetings) {
            int personA = meeting[0];
            int personB = meeting[1];
            int meetingTime = meeting[2];

            // Since meetings are bidirectional, add edges both ways
            adjacencyList
                .computeIfAbsent(personA, k -> new ArrayList<>())
                .add(new int[]{personB, meetingTime});

            adjacencyList
                .computeIfAbsent(personB, k -> new ArrayList<>())
                .add(new int[]{personA, meetingTime});
        }

        // Min-heap priority queue to process people in increasing order of time
        // Each entry is {timeWhenSecretKnown, person}
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(
            (a, b) -> Integer.compare(a[0], b[0])
        );

        // Person 0 has the secret at time 0
        minHeap.offer(new int[]{0, 0});

        // firstPerson also receives the secret at time 0
        minHeap.offer(new int[]{0, firstPerson});

        // Tracks whether a person has already been finalized as knowing the secret
        boolean[] hasSecret = new boolean[n];

        // Process the priority queue (Dijkstra-like traversal)
        while (!minHeap.isEmpty()) {

            // Get the person who knows the secret at the earliest time
            int[] current = minHeap.poll();
            int currentTime = current[0];
            int currentPerson = current[1];

            // If we already processed this person, skip
            if (hasSecret[currentPerson]) {
                continue;
            }

            // Mark this person as having the secret
            hasSecret[currentPerson] = true;

            // Explore all meetings involving this person
            if (!adjacencyList.containsKey(currentPerson)) {
                continue;
            }

            for (int[] neighbor : adjacencyList.get(currentPerson)) {
                int nextPerson = neighbor[0];
                int meetingTime = neighbor[1];

                // The secret can be shared only if:
                // 1. The meeting happens at or after the time currentPerson knows the secret
                // 2. The next person has not already received the secret
                if (meetingTime >= currentTime && !hasSecret[nextPerson]) {
                    minHeap.offer(new int[]{meetingTime, nextPerson});
                }
            }
        }

        // Collect all people who ended up knowing the secret
        List<Integer> peopleWithSecret = new ArrayList<>();
        for (int person = 0; person < n; person++) {
            if (hasSecret[person]) {
                peopleWithSecret.add(person);
            }
        }

        return peopleWithSecret;
    }
}
