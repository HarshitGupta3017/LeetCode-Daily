# Solution for Count Mentions Per User in PY

class Solution:
    # ------------------------------------------------------------
    # Process a MESSAGE event
    # ------------------------------------------------------------
    def processMessageEvent(self, event, mention_count, last_offline_start):
        message_time = int(event[1])
        tokens = event[2].split()

        for token in tokens:

            # Mention ALL users
            if token == "ALL":
                for u in range(len(mention_count)):
                    mention_count[u] += 1

            # Mention online users
            elif token == "HERE":
                for u in range(len(mention_count)):
                    # online if:
                    #   never offline, OR
                    #   offline ended 60s before message
                    if last_offline_start[u] == 0 or \
                       last_offline_start[u] + 60 <= message_time:
                        mention_count[u] += 1

            # Mention id<number>
            else:
                user_id = int(token[2:])
                mention_count[user_id] += 1

    # ------------------------------------------------------------
    # Main function
    # ------------------------------------------------------------
    def countMentions(self, numberOfUsers, events):
        mention_count = [0] * numberOfUsers
        last_offline_start = [0] * numberOfUsers

        # Sort events: OFFLINE before MESSAGE when same timestamp
        def event_sort_key(e):
            t = int(e[1])
            # invert priority: "OFFLINE" comes before "MESSAGE"
            priority = 0 if e[0] == "OFFLINE" else 1
            return (t, priority)

        events.sort(key=event_sort_key)

        # Process events
        for event in events:
            if event[0] == "MESSAGE":
                self.processMessageEvent(event, mention_count, last_offline_start)
            else:  # OFFLINE
                timestamp = int(event[1])
                user_id = int(event[2])
                last_offline_start[user_id] = timestamp

        return mention_count
