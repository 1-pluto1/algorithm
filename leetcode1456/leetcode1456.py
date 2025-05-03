class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        ans = cnt = 0
        for i, c in enumerate(s):
            if c in "aeiou":
                cnt += 1
            if i < k - 1:
                continue
            ans = max(cnt, ans)
            if s[i - k + 1] in "aeiou":
                cnt -= 1
        return ans