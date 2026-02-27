// Solution for Minimum Operations to Equalize Binary String in JAVA

class Solution {
    public int minOperations(String s, int k) {

        int length = s.length();

        // Step 1: count initial zeros
        int initialZeroCount = 0;
        for (char c : s.toCharArray()) {
            if (c == '0') initialZeroCount++;
        }

        if (initialZeroCount == 0)
            return 0;

        int[] visitedOperations = new int[length + 1];
        Arrays.fill(visitedOperations, -1);

        TreeSet<Integer> unvisitedEven = new TreeSet<>();
        TreeSet<Integer> unvisitedOdd = new TreeSet<>();

        for (int z = 0; z <= length; z++) {
            if (z % 2 == 0)
                unvisitedEven.add(z);
            else
                unvisitedOdd.add(z);
        }

        Queue<Integer> queue = new LinkedList<>();

        queue.add(initialZeroCount);
        visitedOperations[initialZeroCount] = 0;

        if (initialZeroCount % 2 == 0)
            unvisitedEven.remove(initialZeroCount);
        else
            unvisitedOdd.remove(initialZeroCount);

        while (!queue.isEmpty()) {

            int currentZeroCount = queue.poll();

            int minZerosFlipped = Math.max(0,
                    k - (length - currentZeroCount));

            int maxZerosFlipped = Math.min(k, currentZeroCount);

            int minNewZeroCount =
                    currentZeroCount + k - 2 * maxZerosFlipped;

            int maxNewZeroCount =
                    currentZeroCount + k - 2 * minZerosFlipped;

            boolean nextParityEven =
                    (minNewZeroCount % 2 == 0);

            TreeSet<Integer> candidateSet =
                    nextParityEven ? unvisitedEven : unvisitedOdd;

            Integer next = candidateSet.ceiling(minNewZeroCount);

            while (next != null && next <= maxNewZeroCount) {

                visitedOperations[next] =
                        visitedOperations[currentZeroCount] + 1;

                if (next == 0)
                    return visitedOperations[next];

                queue.add(next);
                candidateSet.remove(next);

                next = candidateSet.ceiling(minNewZeroCount);
            }
        }

        return -1;
    }
}
