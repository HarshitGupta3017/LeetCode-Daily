// Solution for Maximum Number of Events That Can Be Attended in CPP

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by their start day
        sort(events.begin(), events.end());

        int day = events[0][0];  // Start from the first event's start day
        int totalAttended = 0;   // Counter for number of events attended
        int i = 0;               // Index to track current event
        int n = events.size();

        // Min-heap to keep track of event end days
        priority_queue<int, vector<int>, greater<int>> minHeap;

        while (i < n || !minHeap.empty()) {
            // If heap is empty, move to the next available event's start day
            if (minHeap.empty()) {
                day = events[i][0];
            }

            // Add all events that start on the current day to the heap
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);  // Push the end day
                i++;
            }

            // Attend the event that ends earliest
            if (!minHeap.empty()) {
                minHeap.pop();  // Attend one event
                totalAttended++;
            }

            day++;  // Move to next day

            // Remove events that have already expired
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
        }

        return totalAttended;
    }
};
