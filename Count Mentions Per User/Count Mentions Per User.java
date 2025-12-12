// Solution for Count Mentions Per User in JAVA

import java.util.*;

class Solution {

    // ------------------------------------------------------------
    // Process a MESSAGE event: parse mentions_string and update counts.
    // ------------------------------------------------------------
    private void processMessageEvent(
            List<String> event,
            int[] mentionCount,
            int[] lastOfflineStart
    ) {
        int messageTime = Integer.parseInt(event.get(1));

        // Split the mentions string into tokens
        String[] tokens = event.get(2).split(" ");

        for (String token : tokens) {

            // Mention ALL users
            if (token.equals("ALL")) {
                for (int i = 0; i < mentionCount.length; i++) {
                    mentionCount[i]++;
                }
            }

            // Mention all online users
            else if (token.equals("HERE")) {
                for (int user = 0; user < mentionCount.length; user++) {

                    // A user is online if:
                    //   Never went offline  → lastOfflineStart[user] == 0  
                    //   OR offline ended 60s before message
                    if (lastOfflineStart[user] == 0 ||
                        lastOfflineStart[user] + 60 <= messageTime) {
                        mentionCount[user]++;
                    }
                }
            }

            // Mention id<number>
            else {
                int userId = Integer.parseInt(token.substring(2));
                mentionCount[userId]++;
            }
        }
    }


    public int[] countMentions(int numberOfUsers, List<List<String>> events) {
        int[] mentionCount = new int[numberOfUsers];
        int[] lastOfflineStart = new int[numberOfUsers]; // default 0

        // ------------------------------------------------------------
        // Sort events:
        // If timestamps equal → OFFLINE appears before MESSAGE
        // ------------------------------------------------------------
        events.sort((a, b) -> {
            int t1 = Integer.parseInt(a.get(1));
            int t2 = Integer.parseInt(b.get(1));

            if (t1 == t2) {
                // Compare first char: we want "OFFLINE" first
                return a.get(0).charAt(0) == b.get(0).charAt(0)
                        ? 0
                        : (a.get(0).charAt(0) > b.get(0).charAt(0) ? -1 : 1);
            }
            return Integer.compare(t1, t2);
        });

        // ------------------------------------------------------------
        // Process events
        // ------------------------------------------------------------
        for (List<String> event : events) {

            if (event.get(0).equals("MESSAGE")) {
                processMessageEvent(event, mentionCount, lastOfflineStart);
            } else { // OFFLINE
                int timestamp = Integer.parseInt(event.get(1));
                int userId = Integer.parseInt(event.get(2));
                lastOfflineStart[userId] = timestamp;
            }
        }

        return mentionCount;
    }
}
