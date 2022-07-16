class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        i = 1
        while i < len(intervals):
            times = intervals[i]
            j = 0
            while j < i:
                start, end = intervals[j]
                if start >= times[1] or end <= times[0]:
                    j += 1
                    continue
                else:
                    return False
            i += 1

        return True
