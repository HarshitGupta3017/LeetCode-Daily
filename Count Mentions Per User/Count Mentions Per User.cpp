// Solution for Count Mentions Per User in CPP

class Solution {
public:

    // ------------------------------------------------------------
    // Process a MESSAGE event: parse mentions_string and update counts.
    // ------------------------------------------------------------
    void processMessageEvent(const vector<string>& event,
                             vector<int>& mentionCount,
                             const vector<int>& lastOfflineStart) 
    {
        int messageTime = stoi(event[1]);

        // Split mentions_string into tokens
        vector<string> mentionTokens;
        stringstream splitter(event[2]);
        string token;
        while (splitter >> token) {
            mentionTokens.push_back(token);
        }

        // Process each token
        for (const string& item : mentionTokens) {

            // Mention ALL users
            if (item == "ALL") {
                for (int userId = 0; userId < mentionCount.size(); userId++) {
                    mentionCount[userId]++;
                }
            }
            // Mention all online users
            else if (item == "HERE") {
                for (int userId = 0; userId < mentionCount.size(); userId++) {

                    // User is online if:
                    //    Never been offline -> lastOfflineStart[userId] == 0
                    // OR  Offline period ended -> lastOfflineStart[userId] + 60 <= messageTime
                    if (lastOfflineStart[userId] == 0 ||
                        lastOfflineStart[userId] + 60 <= messageTime) 
                    {
                        mentionCount[userId]++;
                    }
                }
            }
            // Mention a specific user id<number>
            else {
                int userId = stoi(item.substr(2)); // skip "id"
                mentionCount[userId]++;
            }
        }
    }


    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) 
    {
        vector<int> mentionCount(numberOfUsers, 0);

        // Stores the last timestamp at which each user went offline.
        // If = 0 → user has never gone offline (i.e., always online until now)
        vector<int> lastOfflineStart(numberOfUsers, 0);

        // ------------------------------------------------------------
        // Sort events by timestamp, but ensure:
        // OFFLINE events come BEFORE MESSAGE events if timestamps match.
        // ------------------------------------------------------------
        auto compareEvents = [](const vector<string>& e1, const vector<string>& e2) {
            int t1 = stoi(e1[1]);
            int t2 = stoi(e2[1]);

            if (t1 == t2) {
                // "OFFLINE" > "MESSAGE"
                // Compare first character: "OFFLINE"[0]='O', "MESSAGE"[0]='M'
                // We want OFFLINE before MESSAGE → return true if e1 is OFFLINE
                return e1[0][0] > e2[0][0];
            }
            return t1 < t2;
        };

        sort(events.begin(), events.end(), compareEvents);

        // ------------------------------------------------------------
        // Process events in order
        // ------------------------------------------------------------
        for (const auto& event : events) {

            // Handle MESSAGE events
            if (event[0] == "MESSAGE") {
                processMessageEvent(event, mentionCount, lastOfflineStart);
            }

            // Handle OFFLINE event
            else { // event[0] == "OFFLINE"
                int timestamp = stoi(event[1]);
                int userId = stoi(event[2]);

                // Mark offline start time
                lastOfflineStart[userId] = timestamp;
            }
        }

        return mentionCount;
    }
};
