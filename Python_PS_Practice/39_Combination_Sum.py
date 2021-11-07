class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        answer = []
        final_answer = []
        filt = set()
        def dfs(csum, index, path):
            if csum < 0:
                return 
            if csum == 0:
                final_answer.append(path)
                return
            for i in range(index, len(candidates)):
                dfs(csum - candidates[i], i, path + [candidates[i]])
        dfs(target, 0, [])

        return final_answer
