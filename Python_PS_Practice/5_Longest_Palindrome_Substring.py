# brute force
class Solution:
    def longestPalindrome(self, s: str) -> str:
        check = [0 for i in range(len(s))]
        ans = ""
        max_length = 0
        if len(s) == 1:
            return s
        if len(s) == 2:
            if s[0] == s[1]:
                return s
            else:
                return s[0]
        else:
            ans = s[0]
            for i in range(len(s)):
                length = 1
                for j in range(1,len(s)//2 + 1):
                    if i - j >= 0 and i + j < len(s):
                        if s[i-j] == s[i+j]:
                            length += 2
                            if length > max_length:
                                max_length = length
                                ans = s[i-j:i+j+1]
                        else:
                            break
            for i in range(len(s)):
                length = 0
                for j in range(1,len(s)//2  + 1):
                    if i - (j-1) >= 0 and i + j < len(s):
                        if s[i-j+1] == s[i+j]:
                            length += 2
                            if length > max_length:
                                max_length = length
                                ans = s[i-j+1:i+j+1]
                        else:
                            break

            return ans