// Solution for Minimum Jumps to Reach End via Prime Teleportation in JAVA

class Solution {

    // Sieve of Eratosthenes to identify prime numbers
    private void buildSieve(int maximumValue, boolean[] isPrime) {

        Arrays.fill(isPrime, true);

        if (maximumValue >= 0) isPrime[0] = false;
        if (maximumValue >= 1) isPrime[1] = false;

        for (int number = 2; number * number <= maximumValue; number++) {

            if (isPrime[number]) {

                for (int multiple = number * number;
                     multiple <= maximumValue;
                     multiple += number) {

                    isPrime[multiple] = false;
                }
            }
        }
    }

    public int minJumps(int[] nums) {

        int totalElements = nums.length;

        // Map value -> all indices containing that value
        Map<Integer, List<Integer>> valueToIndicesMap = new HashMap<>();

        int maximumValue = 0;

        for (int index = 0; index < totalElements; index++) {

            valueToIndicesMap
                .computeIfAbsent(nums[index], k -> new ArrayList<>())
                .add(index);

            maximumValue = Math.max(maximumValue, nums[index]);
        }

        // Build prime lookup table
        boolean[] isPrime = new boolean[maximumValue + 1];
        buildSieve(maximumValue, isPrime);

        // Standard BFS setup
        Queue<Integer> bfsQueue = new LinkedList<>();

        boolean[] visited = new boolean[totalElements];

        bfsQueue.offer(0);
        visited[0] = true;

        // Prevent repeated processing of same prime teleportation
        Set<Integer> processedPrimes = new HashSet<>();

        int minimumSteps = 0;

        while (!bfsQueue.isEmpty()) {

            int currentLevelSize = bfsQueue.size();

            while (currentLevelSize-- > 0) {

                int currentIndex = bfsQueue.poll();

                // Reached destination
                if (currentIndex == totalElements - 1)
                    return minimumSteps;

                // Adjacent Move: Left
                if (currentIndex - 1 >= 0 &&
                    !visited[currentIndex - 1]) {

                    bfsQueue.offer(currentIndex - 1);
                    visited[currentIndex - 1] = true;
                }

                // Adjacent Move: Right
                if (currentIndex + 1 < totalElements &&
                    !visited[currentIndex + 1]) {

                    bfsQueue.offer(currentIndex + 1);
                    visited[currentIndex + 1] = true;
                }

                int currentValue = nums[currentIndex];

                // Skip if current value is not prime
                // OR prime teleportation already processed
                if (!isPrime[currentValue] ||
                    processedPrimes.contains(currentValue)) {

                    continue;
                }

                // Prime Teleportation
                for (int multiple = currentValue;
                     multiple <= maximumValue;
                     multiple += currentValue) {

                    if (!valueToIndicesMap.containsKey(multiple))
                        continue;

                    for (int nextIndex : valueToIndicesMap.get(multiple)) {

                        if (!visited[nextIndex]) {

                            bfsQueue.offer(nextIndex);
                            visited[nextIndex] = true;
                        }
                    }
                }

                // Mark this prime as processed
                processedPrimes.add(currentValue);
            }

            minimumSteps++;
        }

        return -1;
    }
}
