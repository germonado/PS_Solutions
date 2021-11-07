class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        answer = []
        def dfs(index, tmp_list):
            answer.append(tmp_list)
            if len(tmp_list) >= len(nums):
                return
            for i in range(index+1, len(nums)):
                dfs(i, tmp_list + [nums[i]])
            return

        dfs(-1,[])
        return answer 