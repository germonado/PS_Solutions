class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        answer_intervals = []
        intervals = sorted(intervals, key=lambda x : x[0])
        start, end = intervals[0][0], intervals[0][1]
        for i in range(len(intervals) - 1):
            if end >= intervals[i+1][0]:
                if end < intervals[i+1][1]:
                    end = intervals[i+1][1]
                if start > intervals[i+1][0]:
                    start = intervals[i+1][0]
            else:
                answer_intervals.append([start,end])
                start = intervals[i+1][0]
                end = intervals[i+1][1]
        answer_intervals.append([start,end])
        return answer_intervals