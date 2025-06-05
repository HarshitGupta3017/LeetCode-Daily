// Solution for Lexicographically Smallest Equivalent String in CPP

class Solution {
public:
    // Perform DFS to find the lexicographically smallest character
    // in the equivalence class of the given character
    char findSmallestEquivalentChar(vector<vector<char>>& graph, char currentChar, vector<int>& visited) {
        visited[currentChar - 'a'] = 1;  // Mark as visited
        char smallestChar = currentChar;

        for (const auto& neighbor : graph[currentChar - 'a']) {
            if (!visited[neighbor - 'a']) {
                // Recur and find the minimum character in the connected component
                char candidateChar = findSmallestEquivalentChar(graph, neighbor, visited);
                smallestChar = min(smallestChar, candidateChar);
            }
        }

        return smallestChar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int equivalenceLen = s1.length();  // Same length as s2
        int baseLen = baseStr.length();   // Length of the base string

        // Create adjacency list for all lowercase letters (a-z)
        vector<vector<char>> graph(26);

        // Build the equivalence graph
        for (int i = 0; i < equivalenceLen; i++) {
            char charFromS1 = s1[i];
            char charFromS2 = s2[i];
            graph[charFromS1 - 'a'].push_back(charFromS2);
            graph[charFromS2 - 'a'].push_back(charFromS1);
        }

        string result = "";

        // For each character in baseStr, find its smallest equivalent character
        for (const auto& baseChar : baseStr) {
            vector<int> visited(26, 0);  // Track visited characters in DFS
            char smallestEquivalent = findSmallestEquivalentChar(graph, baseChar, visited);
            result.push_back(smallestEquivalent);
        }

        return result;
    }
};
