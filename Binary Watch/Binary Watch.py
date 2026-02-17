# Solution for Binary Watch in PY

class Solution:
    def readBinaryWatch(self, turnedOn: int):
        
        possible_times = []
        
        for hour in range(12):
            for minute in range(60):
                
                # Count total bits ON
                total_bits_on = bin(hour).count('1') + bin(minute).count('1')
                
                if total_bits_on == turnedOn:
                    
                    # Format minute with leading zero
                    time_str = f"{hour}:{minute:02d}"
                    
                    possible_times.append(time_str)
        
        return possible_times
