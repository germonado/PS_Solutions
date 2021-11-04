import collections
# My solution
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        answer = []
        strs_dict = {}
        index = 0
        for i in strs:
            tmp = collections.Counter(i)
            tmp_list = []
            for k, v in tmp.items():
                tmp_list.append(k+str(v))
            tmp_list.sort()
            tmp_list = ''.join(tmp_list)
            if tmp_list in strs_dict:
                answer[strs_dict[tmp_list]].append(i)
            else:
                answer.append([i])
                strs_dict[tmp_list] = index
                index += 1
        return answer