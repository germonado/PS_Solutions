# personally, I think pop behavior is not necessary in this problem
# solution 1, speed is not optimized
strs = []
for char in s:
    if char.isalnum():
        strs.append(char.lower())
while len(strs) > 1:
    if strs.pop(0) != strs.pop():
        return False
return True

# solution 2, with deque
strs : Deque = collections.deque()
for char in s:
    if char.isalnum():
        strs.append(char.lower())
    
while len(strs) > 1:
    if strs.popleft() != strs.pop():
        return False

return True

# solution 3, with slicing
s = s.lower()
s = re.sub('[^a-z0-9','',s)
return s == s[::-1]

# my solution
class Solution:
    def isPalindrome(self, s: str) -> bool:
        if len(s) == 1: return True
        s = s.lower()
        a = []
        for i in range(len(s)):
            if s[i] >= 'a' and s[i] <= 'z':
                a.append(s[i])
            elif s[i] >= '0' and s[i] <= '9':
                a.append(s[i])
        
        for i in range(len(a)//2):
            if a[i] != a[len(a) - 1 - i]:
                return False
        return True