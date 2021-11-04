class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        find_min = 987654321
        find_max = 0
        val_max = 0
        deq = collections.deque()
        for i in range(len(prices)):
            if prices[i] < find_min:
                find_min = prices[i]
                while len(deq) > 0 and deq[-1] > find_min:
                    deq.popleft()
                deq.append(prices[i])
            elif deq[-1] < prices[i]:
                deq.append(prices[i])
                if deq[-1] - deq[0] > val_max:
                    val_max = deq[-1] - deq[0]
        return val_max
