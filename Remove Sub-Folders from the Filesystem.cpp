class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // simple ques in which we can just sort the folder
        // so that all sub foldes will come after the main one as sub folders will start from main 
        // ones only, for example - 
        // main folder - "/a", sub-folder - "/a/b"
        // so we can see sub-folder contains "main folder path + '/' + 'sub-folder'"
        // this can be used for checking after sorting
        sort(folder.begin(), folder.end());
        vector<string> res;
        for(const string& f: folder) {
            // if result is empty we can just add folder to the result at start as it will be main only
            // also we will check if "main folder path + '/'" is present in upcoming sub-folder
            // if yes than its a sub-folder we won't add in result otherwise add
            // how to check that??
            // for getting last element from vector we can use res.back() and can add '/'
            // after finding this in f i.e. sub-folder it will return 2 things
            // 1st - if it startswith main-folder then it will return 0 because it will start from that 
            // 2nd - if it is not present than wherever its present it will return that index but
            // it won't be present that only when we add it in result so it will return -1
            // so if its not 0 that means not present so add to result
            if (res.empty() || f.find(res.back() + '/') != 0) res.push_back(f);
        }
        return res;
    }
};
