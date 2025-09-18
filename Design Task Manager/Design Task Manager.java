// Solution for Design Task Manager in JAVA

class TaskManager {
    // Maps taskId → priority
    private Map<Integer, Integer> taskPriority = new HashMap<>();

    // Maps taskId → userId
    private Map<Integer, Integer> taskUser = new HashMap<>();

    // Max-heap: {priority, taskId}, ordered by priority first, then taskId
    private PriorityQueue<int[]> maxHeap;

    // Constructor: initialize with given tasks
    public TaskManager(List<List<Integer>> tasks) {
        // Custom comparator: higher priority first, if equal then smaller taskId first
        maxHeap = new PriorityQueue<>((a, b) -> {
            if (b[0] != a[0]) return b[0] - a[0];  // compare by priority
            return b[1] - a[1];                    // tie-break by taskId
        });

        for (List<Integer> task : tasks) {
            add(task.get(0), task.get(1), task.get(2));
        }
    }

    // Add a new task for a user
    public void add(int userId, int taskId, int priority) {
        taskPriority.put(taskId, priority);
        taskUser.put(taskId, userId);
        maxHeap.offer(new int[]{priority, taskId});
    }

    // Edit priority of an existing task
    public void edit(int taskId, int newPriority) {
        taskPriority.put(taskId, newPriority);
        maxHeap.offer(new int[]{newPriority, taskId}); // lazy deletion handles outdated entries
    }

    // Remove a task completely (mark as invalid)
    public void rmv(int taskId) {
        taskPriority.put(taskId, -1); // mark invalid
    }

    // Execute (remove + return userId of) highest priority task
    public int execTop() {
        while (!maxHeap.isEmpty()) {
            int[] top = maxHeap.poll();
            int priority = top[0];
            int taskId = top[1];

            // Check if this is still valid
            if (priority == taskPriority.getOrDefault(taskId, -1)) {
                taskPriority.put(taskId, -1); // mark executed
                return taskUser.get(taskId);
            }
        }
        return -1; // no tasks available
    }
}
