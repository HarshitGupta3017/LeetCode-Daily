# Solution for Avoid Flood in The City in PY

class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        n = len(rains)
        last_rain_day = {}   # lake -> last day it rained
        dry_days = []        # sorted list of available dry days
        result = [1] * n     # default value for dry days

        for day, lake in enumerate(rains):
            if lake == 0:
                # Dry day, store index
                bisect.insort(dry_days, day)
            else:
                result[day] = -1
                if lake in last_rain_day:
                    # Find the first dry day after last rain
                    idx = bisect.bisect_right(dry_days, last_rain_day[lake])
                    if idx == len(dry_days):
                        return []  # no available dry day → flood
                    dry_day = dry_days.pop(idx)
                    result[dry_day] = lake
                last_rain_day[lake] = day

        return result
