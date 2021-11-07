class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if len(prerequisites) == 0:
            return True
        indegree = collections.defaultdict(int)
        info = collections.defaultdict(list)
        heap = []
        for i in range(len(prerequisites)):
            indegree[prerequisites[i][0]] += 0
            indegree[prerequisites[i][1]] += 1
            info[prerequisites[i][0]].append(prerequisites[i][1])
        for k, v in indegree.items():
            heapq.heappush(heap, (v, k))
        while heap:
            cnt, val = heapq.heappop(heap)
            if cnt > 0:
                break
            for i in info[val]:
                indegree[i] -= 1
                if indegree[i] >= 0:
                    heapq.heappush(heap, (indegree[i], i))
        for k, v in indegree.items():
            if v > 0:
                return False
        return True