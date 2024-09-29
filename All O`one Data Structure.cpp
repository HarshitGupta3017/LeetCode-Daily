class AllOne {
public:
    unordered_map<string, int> countMap;
    map<int, unordered_set<string>> freqMap;

    AllOne() {}
    
    void inc(string key) {
        int count = countMap[key];
        if (count > 0) {
            freqMap[count].erase(key);
            if (freqMap[count].empty()) freqMap.erase(count);
        }
        countMap[key] = count + 1;
        freqMap[count + 1].insert(key);
    }
    
    void dec(string key) {
        int count = countMap[key];
        freqMap[count].erase(key);
        if (freqMap[count].empty()) freqMap.erase(count);
        if (count == 1) {
            countMap.erase(key);
        } else {
            countMap[key] = count - 1;
            freqMap[count - 1].insert(key);
        }
    }
    
    string getMaxKey() {
        if (freqMap.empty()) return "";
        return *(freqMap.rbegin()->second.begin());
    }
    
    string getMinKey() {
        if (freqMap.empty()) return "";
        return *(freqMap.begin()->second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
