// Solution for Find Closest Node to Given Two Nodes in CPP

class Solution {
public:

    // Computes shortest distances from startNode to all reachable nodes in the graph
    vector<int> computeDistancesFromNode(vector<int>& edges, int startNode, int totalNodes) {
        vector<int> distance(totalNodes, -1); // -1 indicates unreachable nodes
        distance[startNode] = 0;

        queue<int> bfsQueue;
        bfsQueue.push(startNode);

        while (!bfsQueue.empty()) {
            int currentNode = bfsQueue.front();
            bfsQueue.pop();

            int nextNode = edges[currentNode]; // directed edge to next node
            if (nextNode != -1 && distance[nextNode] == -1) {
                distance[nextNode] = distance[currentNode] + 1;
                bfsQueue.push(nextNode);
            }
        }

        return distance;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int totalNodes = edges.size();

        // Compute distance arrays from node1 and node2
        vector<int> distanceFromNode1 = computeDistancesFromNode(edges, node1, totalNodes);
        vector<int> distanceFromNode2 = computeDistancesFromNode(edges, node2, totalNodes);

        int minimumOfMaximumDistances = INT_MAX;
        int closestNode = -1;

        // Iterate through each node to find the optimal meeting node
        for (int node = 0; node < totalNodes; node++) {
            // Check if the node is reachable from both node1 and node2
            if (distanceFromNode1[node] != -1 && distanceFromNode2[node] != -1) {
                int maxDistance = max(distanceFromNode1[node], distanceFromNode2[node]);

                // Update if a better (smaller) maxDistance is found
                // If tied, choose the node with the smaller index
                if (maxDistance < minimumOfMaximumDistances ||
                   (maxDistance == minimumOfMaximumDistances && node < closestNode)) {
                    minimumOfMaximumDistances = maxDistance;
                    closestNode = node;
                }
            }
        }

        return closestNode;
    }
};
