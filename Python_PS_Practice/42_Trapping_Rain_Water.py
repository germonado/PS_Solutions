class Solution:
    def trap(self, height: List[int]) -> int:
        stack = []
        volume = 0
        for i in range(len(height)):
            while stack and height[i] > height[stack[-1]]:
                top = stack.pop()
                if not len(stack):
                    break
                
                distance = i - stack[-1] - 1
                waters = min(height[i], height[stack[-1]]) - height[top]
                volume += distance * waters
            stack.append(i)
        
        return volume

class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        left_max = height[0]
        right_max = height[-1]
        answer = 0
        while left < right:
            left_max = max(left_max, height[left])
            right_max = max(right_max, height[right])
            if left_max <= right_max:
                answer += left_max - height[left]
                left += 1
            else:
                answer += right_max - height[right]
                right -= 1

        return answer