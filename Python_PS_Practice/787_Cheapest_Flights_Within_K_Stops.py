class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        node_info = collections.defaultdict(list)
        visited = dict()
        for i in flights:
            node_info[i[0]].append((i[1], i[2]))

        start = (0, src, 0)
        heap = []
        heapq.heappush(heap, start)
        dist = [987654321 for i in range(n+1)]
        dist[src] = 0
        visited[src] = 1
        answer = 987654321
        while heap:
            current = heapq.heappop(heap)
            current_cost, current_node, current_k = current[2], current[1], current[0]
            if current_k <= k + 1 and current_node == dst:
                if answer > current_cost:
                    answer = current_cost
            if current_k + 1 <= k + 1:
                for next_n in node_info[current_node]:
                    next_node = next_n[0]
                    next_cost = next_n[1]
                    new_cost = next_cost + current_cost
                    if new_cost > answer:
                        continue
                    if not next_node in visited or dist[next_node] > new_cost:
                        visited[next_node] = 1
                        dist[next_node] = new_cost
                        heapq.heappush(heap, (current_k+1, next_node, new_cost))
                
        if answer != 987654321:
            return answer
        else:
            return -1