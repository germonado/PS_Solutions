class Solution:
    def __init__(self):
        self.ans = []

    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) <= 2:
            return []
        nums.sort()
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            x = nums[i]
            left = i + 1
            right = len(nums) - 1
            while left < right:
                tmp = x + nums[left] + nums[right]
                if tmp == 0:
                    self.ans.append([x, nums[left], nums[right]])
                    while left < right and nums[left] == nums[left+1]:
                        left += 1
                    while left < right and nums[right] == nums[right-1]:
                        right -=1
                    left += 1
                    right -= 1
                elif tmp > 0:
                    right -=1
                elif tmp < 0:
                    left += 1

        return self.ans