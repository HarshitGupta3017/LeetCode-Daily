# Solution for Minimum Initial Energy to Finish Tasks in PY

class Solution:
    def minimumEffort(self, tasks):

        # Sort by (minimum - actual) descending
        tasks.sort(key=lambda t: t[1] - t[0], reverse=True)

        min_start_energy = 0
        energy_consumed = 0

        for actual, minimum in tasks:

            min_start_energy = max(
                min_start_energy,
                energy_consumed + minimum
            )

            energy_consumed += actual

        return min_start_energy
