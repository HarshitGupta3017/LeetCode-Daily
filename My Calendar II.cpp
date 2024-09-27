class MyCalendarTwo {
public:
    map<int, int> mp;
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int active = 0;
        for (const auto& [time, count]: mp) {
            active += count;
            if (active == 3) {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
