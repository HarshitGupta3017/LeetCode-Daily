// Solution for Compare Version Numbers in CPP

class Solution {
public:
    // Helper function: split a version string into integer parts
    // Example: "1.01.3" -> [1, 1, 3]
    vector<int> splitVersion(const string& version) {
        vector<int> parts;          // Stores numeric values of revisions
        string token;               // Temporary string for each revision part
        stringstream ss(version);   // Use stringstream to split by '.'

        // Extract tokens separated by '.' from the version string
        while (getline(ss, token, '.')) {
            // Convert token to integer (stoi removes leading zeros automatically)
            parts.push_back(stoi(token));
        }
        return parts;   // Return the list of integer revisions
    }

    // Function to compare two version strings
    int compareVersion(string version1, string version2) {
        // Convert both versions into integer arrays
        vector<int> v1 = splitVersion(version1);
        vector<int> v2 = splitVersion(version2);

        int m = v1.size();  // Number of revisions in version1
        int n = v2.size();  // Number of revisions in version2
        int maxLength = max(m, n);  // Compare up to the longer version length

        // Compare revisions one by one from left to right
        for (int i = 0; i < maxLength; i++) {
            // If one version is shorter, treat missing parts as 0
            int num1 = (i < m ? v1[i] : 0);
            int num2 = (i < n ? v2[i] : 0);

            // Compare current revision numbers
            if (num1 < num2) return -1;   // version1 < version2
            if (num1 > num2) return 1;    // version1 > version2
            // If equal, continue checking next revision
        }

        // If all revisions are equal, return 0
        return 0;
    }
};
