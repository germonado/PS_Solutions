import collections
import re
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        banned_words = set()
        for i in banned:
            banned_words.add(i)
        banned_words.add('')
        paragraph = paragraph.split(',')
        words = []
        for i in paragraph:
            i = i.split(' ')
            for j in i:
                tmp = re.sub('[^a-z]','',j.lower())
                if not tmp in banned_words:
                    words.append(tmp)
        return collections.Counter(words).most_common(1)[0][0]
        