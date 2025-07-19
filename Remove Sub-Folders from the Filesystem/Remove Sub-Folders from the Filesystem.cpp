// Solution for Remove Sub-Folders from the Filesystem in CPP

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Step 1: Sort the folder paths lexicographically
        // This makes sure that parent folders (like "/a") come before subfolders (like "/a/b")
        sort(folder.begin(), folder.end());

        // Step 2: This will store the final result (only parent folders, no subfolders)
        vector<string> res;

        // Step 3: Traverse each folder path
        for (const string& f : folder) {
            /*
                Step 3a: Check if the current folder `f` is a sub-folder of the last added one:
                - res.back() gives the last folder added to the result.
                - We add '/' to it because "/a" should match "/a/" for "/a/b", but not "/ab".
                - If `f` starts with `res.back() + '/'`, then it's a sub-folder and should be skipped.
                - If not, it's a valid top-level folder, so we add it.
            */
            if (res.empty() || f.find(res.back() + '/') != 0) {
                res.push_back(f);  // It's not a subfolder → add to result
            }
        }

        // Step 4: Return the final list of folders with all subfolders removed
        return res;
    }
};
