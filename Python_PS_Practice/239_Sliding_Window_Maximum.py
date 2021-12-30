class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        max_value_lists = []
        compare_deque = collections.deque()
        # first search
        max_value = -2000000
        for i in range(k):
            while compare_deque and compare_deque[-1][0] < nums[i]:
                compare_deque.pop()
            compare_deque.append((nums[i], i))
            if max_value < nums[i]:
                max_value = nums[i]
        max_value_lists.append(max_value)

        for index in range(k, len(nums)):
            while compare_deque and compare_deque[-1][0] < nums[index]:
                compare_deque.pop()
            while compare_deque and compare_deque[0][1] <= index-k:
                compare_deque.popleft()
            compare_deque.append((nums[index],index))
            max_value_lists.append(compare_deque[0][0])
        return max_value_lists