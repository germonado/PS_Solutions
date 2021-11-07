# Dijkstra with heapq and dictionary
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        node_dict = collections.defaultdict(dict)
        node_cost = collections.defaultdict(dict)
        for i in times:
            node_dict[i[0]][i[1]] = 987654321
            node_cost[i[0]][i[1]] = i[2]
        queue = []
        heapq.heappush(queue,(0,k))
        ans = [987654321 for i in range(n+1)]
        ans[k] = 0
        total_cost = -1
        while queue:
            current = heapq.heappop(queue)
            for next_v, next_c in node_dict[current[1]].items():
                cost_val = min(node_cost[current[1]][next_v] + current[0], ans[next_v])
                if ans[next_v] > cost_val:
                    heapq.heappush(queue,(cost_val, next_v))
                ans[next_v] = min(cost_val, ans[next_v])
        count = 0
        for i in ans:
            if i == 987654321:
                count += 1
                if count > 1:
                    return -1
            elif i != 987654321 and i != 0:
                if i > total_cost:
                    total_cost = i

        return total_cost