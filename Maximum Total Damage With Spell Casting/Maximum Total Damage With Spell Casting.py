# Solution for Maximum Total Damage With Spell Casting in PY

class Solution:
    def computeMaxDamage(self, unique_damages: List[int], i: int, memo: List[int], damage_count_map: dict) -> int:
        # Base case
        if i >= len(unique_damages):
            return 0

        # Return memoized result
        if memo[i] != -1:
            return memo[i]

        # Option 1: Skip current damage
        skip_current = self.computeMaxDamage(unique_damages, i + 1, memo, damage_count_map)

        # Option 2: Take current damage and skip incompatible ones
        current_damage = unique_damages[i]
        next_index = bisect.bisect_right(unique_damages, current_damage + 2)

        take_current = current_damage * damage_count_map[current_damage] + \
                       self.computeMaxDamage(unique_damages, next_index, memo, damage_count_map)

        # Store result
        memo[i] = max(skip_current, take_current)
        return memo[i]

    def maximumTotalDamage(self, power: List[int]) -> int:
        # Count occurrences of each damage value
        damage_count_map = {}
        for dmg in power:
            damage_count_map[dmg] = damage_count_map.get(dmg, 0) + 1

        # Extract and sort unique damages
        unique_damages = sorted(damage_count_map.keys())

        memo = [-1] * len(unique_damages)

        # Compute result
        return self.computeMaxDamage(unique_damages, 0, memo, damage_count_map)
