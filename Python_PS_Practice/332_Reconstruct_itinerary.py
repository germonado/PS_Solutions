class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        itinerary = collections.defaultdict(list)
        answer = []
        for i in sorted(tickets):
            itinerary[i[0]].append(i[1])
        def dfs(bef):
            while itinerary[bef]:
                dfs(itinerary[bef].pop(0))
            answer.append(bef)
        dfs("JFK")
        return answer[::-1]

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        itinerary = collections.defaultdict(list)
        answer = []
        for i in sorted(tickets):
            itinerary[i[0]].append(i[1])
        stack = ["JFK"]
        while stack:
            while itinerary[stack[-1]]:
                stack.append(itinerary[stack[-1]].pop(0))
            answer.append(stack.pop())
        return answer[::-1]