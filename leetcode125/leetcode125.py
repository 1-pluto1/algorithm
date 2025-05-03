# class Solution:
#     def isPalindrome(self, s: str) -> bool:
#         s = ''.join(filter(str.isalnum, s)).lower()
#         return s == s[::-1]

class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1
        while left < right:
            if not s[left].isalnum():
                left += 1
            elif not s[right].isalnum():
                right -= 1
            elif s[left].lower() == s[right].lower():
                left += 1
                right -= 1
            else:
                return False
        return True