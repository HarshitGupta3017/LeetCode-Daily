// Solution for Delete Duplicate Folders in System in CPP

class Solution {
public:
    // Node represents a folder and its subfolders
    struct Node {
        string val;  // Folder name
        string subFolder;  // Serialized subtree of this node (used for detecting duplicates)
        unordered_map<string, Node*> children;  // Map of child folder name -> Node
    };

    // Helper to create a new node with the folder name
    Node* getNode(string val) {
        Node* temp = new Node();
        temp->val = val;
        temp->subFolder = "";
        return temp;
    }

    // Insert a folder path into the Trie
    void insert(Node* root, vector<string>& path) {
        for (auto& folder : path) {
            // If folder not present at this level, create it
            if (!root->children.count(folder)) {
                root->children[folder] = getNode(folder);
            }
            // Move to the next level (deeper folder)
            root = root->children[folder];
        }
    }

    // Serialize subtrees (used to identify duplicates)
    string populateNodes(Node* root, unordered_map<string, int>& subFolderMap) {
        vector<pair<string, string>> subFolderPaths;

        // Traverse each child and serialize its subtree
        for (auto& [childName, child] : root->children) {
            string subFolderResult = populateNodes(child, subFolderMap);
            subFolderPaths.push_back({childName, subFolderResult});
        }

        // Sort to avoid issues with unordered_map order
        sort(begin(subFolderPaths), end(subFolderPaths));

        // Combine all serialized children into one string
        string completePath = "";
        for (auto& [childName, childPath] : subFolderPaths) {
            completePath += "(" + childName + childPath + ")";
        }

        root->subFolder = completePath;

        // Count how many times this subtree structure appears
        if (!completePath.empty()) {
            subFolderMap[completePath]++;
        }

        return completePath;
    }

    // Delete all folders with duplicate subtree structures
    void removeDuplicates(Node* root, unordered_map<string, int>& subFolderMap) {
        // Iterate through children using iterator (as we may erase entries)
        for (auto it = root->children.begin(); it != root->children.end();) {
            Node* child = it->second;

            // If child subtree is a duplicate, erase it
            if (!child->subFolder.empty() && subFolderMap[child->subFolder] > 1) {
                it = root->children.erase(it);  // Also deletes all its subfolders
            } else {
                // Recurse deeper to check grandchildren
                removeDuplicates(child, subFolderMap);
                ++it;
            }
        }
    }

    // Reconstruct the paths from the cleaned Trie
    void constructResult(Node* root, vector<string>& path, vector<vector<string>>& result) {
        for (auto& [childName, child] : root->children) {
            path.push_back(childName);     // Add folder to current path
            result.push_back(path);        // Save current valid path
            constructResult(child, path, result); // Go deeper
            path.pop_back();               // Backtrack
        }
    }

    // Main function to delete duplicate folders
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = getNode("/");  // Root of our virtual Trie

        // Step 1: Build the Trie from input paths
        for (auto& path : paths) {
            insert(root, path);
        }

        unordered_map<string, int> subFolderMap;

        // Step 2: Serialize each subtree to detect duplicates
        populateNodes(root, subFolderMap);

        // Step 3: Delete all duplicate subtrees
        removeDuplicates(root, subFolderMap);

        // Step 4: Reconstruct the final folder paths
        vector<vector<string>> result;
        vector<string> path;
        constructResult(root, path, result);

        return result;
    }
};
