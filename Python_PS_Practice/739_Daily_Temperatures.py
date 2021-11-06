class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer = [0 for i in range(len(temperatures))]
        if len(temperatures) <= 1:
            return [0]
        stack = collections.deque()
        stack.append(0)
        ans = []
        for i in range(1,len(temperatures)):
            # if stack top is bigger
            if temperatures[stack[-1]] > temperatures[i]:
                stack.append(i)
            else:
                while stack:
                    if temperatures[stack[-1]] < temperatures[i]:
                        answer[stack[-1]] += (i - stack[-1])
                        stack.pop()
                    else:
                        break
                stack.append(i)

        return answer