// Solution for Jump Game IV in JAVA

class Solution {
    public int minJumps(int[] arr) {

        int totalElements = arr.length;

        // Store all indices corresponding to each value
        Map<Integer, List<Integer>> valueIndicesMap = new HashMap<>();

        for (int index = 0; index < totalElements; index++) {
            valueIndicesMap
                .computeIfAbsent(arr[index], k -> new ArrayList<>())
                .add(index);
        }

        // Standard BFS setup
        Queue<Integer> bfsQueue = new LinkedList<>();
        bfsQueue.offer(0);

        boolean[] visited = new boolean[totalElements];
        visited[0] = true;

        int steps = 0;

        while (!bfsQueue.isEmpty()) {

            int currentLevelSize = bfsQueue.size();

            while (currentLevelSize-- > 0) {

                int currentIndex = bfsQueue.poll();

                // Reached last index
                if (currentIndex == totalElements - 1) {
                    return steps;
                }

                // Move to previous index
                if (currentIndex - 1 >= 0 && !visited[currentIndex - 1]) {
                    visited[currentIndex - 1] = true;
                    bfsQueue.offer(currentIndex - 1);
                }

                // Move to next index
                if (currentIndex + 1 < totalElements && !visited[currentIndex + 1]) {
                    visited[currentIndex + 1] = true;
                    bfsQueue.offer(currentIndex + 1);
                }

                // Jump to all indices having same value
                if (valueIndicesMap.containsKey(arr[currentIndex])) {

                    for (int nextIndex : valueIndicesMap.get(arr[currentIndex])) {

                        if (!visited[nextIndex]) {
                            visited[nextIndex] = true;
                            bfsQueue.offer(nextIndex);
                        }
                    }

                    // Remove processed value group
                    valueIndicesMap.remove(arr[currentIndex]);
                }
            }

            steps++;
        }

        return steps;
    }
}
