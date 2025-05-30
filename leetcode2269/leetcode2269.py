class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        s = str(num)
        ans = 0
        for i in range(k, len(s) + 1):
            x = int(s[i - k: i])
            if x > 0 and num % x == 0:
                ans += 1
        return ans