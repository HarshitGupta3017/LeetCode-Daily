// Solution for Design Task Manager in CPP

class TaskManager {
public:
    // Maps taskId → priority
    unordered_map<int, int> taskPriority;

    // Maps taskId → userId
    unordered_map<int, int> taskUser;

    // Max-heap: {priority, taskId}, ordered by priority first, then taskId
    priority_queue<pair<int, int>> maxHeap;

    // Constructor: initialize with given tasks
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    // Add a new task for a user
    void add(int userId, int taskId, int priority) {
        taskPriority[taskId] = priority;
        taskUser[taskId] = userId;
        maxHeap.push({priority, taskId});
    }

    // Edit priority of an existing task
    void edit(int taskId, int newPriority) {
        taskPriority[taskId] = newPriority;
        maxHeap.push({newPriority, taskId}); // push new version, lazy deletion handles old ones
    }

    // Remove a task completely (mark as invalid)
    void rmv(int taskId) {
        taskPriority[taskId] = -1; // mark invalid
    }

    // Execute (remove + return userId of) highest priority task
    int execTop() {
        while (!maxHeap.empty()) {
            auto [priority, taskId] = maxHeap.top();
            maxHeap.pop();

            // Check if this is still the valid task (not outdated/removed)
            if (priority == taskPriority[taskId]) {
                taskPriority[taskId] = -1; // mark executed
                return taskUser[taskId];
            }
        }
        return -1; // no tasks available
    }
};
