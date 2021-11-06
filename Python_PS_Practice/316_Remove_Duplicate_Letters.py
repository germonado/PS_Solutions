class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        counter = collections.Counter(s)
        seen = set()
        stack = []
        for i in s:
            counter[i] -= 1
            if i in seen:
                continue
            else:
                while stack and i < stack[-1] and counter[stack[-1]] >= 1:
                    seen.remove(stack.pop())
                stack.append(i)
                seen.add(i)

        return ''.join(stack)
# Recursive Way
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        for char in sorted(set(s)):
            suffix = s[s.index(char):]
            if set(s) == set(suffix):
                return char + self.removeDuplicateLetters(suffix.replace(char,''))
        return ''
