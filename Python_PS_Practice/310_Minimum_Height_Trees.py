import collections
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        count_dict = collections.defaultdict(list)
        if n <= 1:
            return [0]
        for i in edges:
            count_dict[i[0]].append(i[1])
            count_dict[i[1]].append(i[0])
        leaves = []
        for i in range(n):
            if len(count_dict[i]) == 1:
                leaves.append(i)
        while n > 2:
            n -= len(leaves)
            new_leaves = []
            for leaf in leaves:
                neighbor = count_dict[leaf].pop()
                count_dict[neighbor].remove(leaf)
                if len(count_dict[neighbor]) == 1:
                    new_leaves.append(neighbor)
            leaves = new_leaves
        return leaves