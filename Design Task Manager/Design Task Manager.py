# Solution for Design Task Manager in PY

class TaskManager:

    def __init__(self, tasks: List[List[int]]):
        self.taskPriority = {}   # taskId -> priority
        self.taskUser = {}       # taskId -> userId
        # max-heap with (-priority, -taskId) so largest priority & largest taskId come first
        self.maxHeap = []

        for userId, taskId, priority in tasks:
            self.add(userId, taskId, priority)

    def add(self, userId: int, taskId: int, priority: int) -> None:
        self.taskPriority[taskId] = priority
        self.taskUser[taskId] = userId
        heapq.heappush(self.maxHeap, (-priority, -taskId))

    def edit(self, taskId: int, newPriority: int) -> None:
        self.taskPriority[taskId] = newPriority
        heapq.heappush(self.maxHeap, (-newPriority, -taskId))

    def rmv(self, taskId: int) -> None:
        self.taskPriority[taskId] = -1

    def execTop(self) -> int:
        while self.maxHeap:
            negPriority, negTaskId = heapq.heappop(self.maxHeap)
            taskId = -negTaskId
            priority = -negPriority
            if self.taskPriority.get(taskId, -1) == priority:
                self.taskPriority[taskId] = -1
                return self.taskUser[taskId]
        return -1
