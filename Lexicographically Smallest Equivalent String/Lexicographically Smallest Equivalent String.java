// Solution for Lexicographically Smallest Equivalent String in JAVA

class Solution {

    private char findSmallestEquivalentChar(List<List<Character>> graph, char currentChar, boolean[] visited) {
        visited[currentChar - 'a'] = true;
        char smallestChar = currentChar;

        for (char neighbor : graph.get(currentChar - 'a')) {
            if (!visited[neighbor - 'a']) {
                char candidateChar = findSmallestEquivalentChar(graph, neighbor, visited);
                if (candidateChar < smallestChar) {
                    smallestChar = candidateChar;
                }
            }
        }

        return smallestChar;
    }

    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        int equivalenceLen = s1.length();
        List<List<Character>> graph = new ArrayList<>();

        for (int i = 0; i < 26; i++) {
            graph.add(new ArrayList<>());
        }

        // Build graph
        for (int i = 0; i < equivalenceLen; i++) {
            char u = s1.charAt(i);
            char v = s2.charAt(i);
            graph.get(u - 'a').add(v);
            graph.get(v - 'a').add(u);
        }

        StringBuilder result = new StringBuilder();

        for (char baseChar : baseStr.toCharArray()) {
            boolean[] visited = new boolean[26];
            char smallest = findSmallestEquivalentChar(graph, baseChar, visited);
            result.append(smallest);
        }

        return result.toString();
    }
}
