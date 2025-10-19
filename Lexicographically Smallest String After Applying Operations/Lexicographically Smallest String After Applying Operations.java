// Solution for Lexicographically Smallest String After Applying Operations in JAVA

class Solution {
    public String findLexSmallestString(String s, int a, int b) {
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        queue.offer(s);
        visited.add(s);

        String smallest = s;

        while (!queue.isEmpty()) {
            String curr = queue.poll();
            if (curr.compareTo(smallest) < 0) {
                smallest = curr;
            }

            // ---- Operation 1: Add 'a' to all odd indices ----
            char[] chars = curr.toCharArray();
            for (int i = 1; i < chars.length; i += 2) {
                int digit = (chars[i] - '0' + a) % 10;
                chars[i] = (char) (digit + '0');
            }
            String added = new String(chars);
            if (!visited.contains(added)) {
                visited.add(added);
                queue.offer(added);
            }

            // ---- Operation 2: Rotate right by 'b' ----
            String rotated = curr.substring(curr.length() - b) + curr.substring(0, curr.length() - b);
            if (!visited.contains(rotated)) {
                visited.add(rotated);
                queue.offer(rotated);
            }
        }

        return smallest;
    }
}
