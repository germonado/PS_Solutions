class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = 1
        products = []
        answer = [nums[0]]
        calc = [nums[len(nums) - 1]]
        for i in range(1,len(nums)):
            answer.append(nums[i] * answer[i-1])
        ind = 0
        for i in range(len(nums) - 2, -1, -1):
            calc.append(calc[ind] * nums[i])
            ind += 1
        calc.reverse()
        products = [calc[1]]
        for i in range(1,len(answer)):
            if i + 1 <= len(calc) - 1:
                products.append(answer[i-1] * calc[i+1])
        products.append(answer[len(answer) - 2])
        return products
        