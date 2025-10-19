// Solution for Lexicographically Smallest String After Applying Operations in CPP

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> stateQueue;          // Queue to perform BFS over all possible strings
        unordered_set<string> visitedStates;         // To track visited strings and prevent reprocessing

        stateQueue.push(s);
        visitedStates.insert(s);

        string smallestString = s;         // Store the lexicographically smallest string found

        while (!stateQueue.empty()) {
            string current = stateQueue.front();
            stateQueue.pop();

            // Update result if current string is lexicographically smaller
            smallestString = min(smallestString, current);

            // -------- Operation 1: Add 'a' to all odd indices --------
            string addedString = current;
            for (int i = 1; i < addedString.size(); i += 2) {
                // Add 'a' to digit and wrap around using modulo 10
                addedString[i] = ((addedString[i] - '0' + a) % 10) + '0';
            }

            // If new string not seen before, enqueue it
            if (!visitedStates.count(addedString)) {
                stateQueue.push(addedString);
                visitedStates.insert(addedString);
            }

            // -------- Operation 2: Rotate string to the right by 'b' --------
            string rotatedString = current.substr(current.size() - b) + current.substr(0, current.size() - b);

            // If new string not seen before, enqueue it
            if (!visitedStates.count(rotatedString)) {
                stateQueue.push(rotatedString);
                visitedStates.insert(rotatedString);
            }
        }

        // Return the smallest lexicographical string found
        return smallestString;
    }
};
