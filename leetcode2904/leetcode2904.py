class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        if s.count('1') < k:
            return ''
        ans = s
        cnt1 = left = 0
        for right, c in enumerate(s):
            cnt1 += int(c)
            while cnt1 > k or s[left] == '0':
                cnt1 -= int(s[left])
                left += 1
            if cnt1 == k:
                t = s[left: right + 1]
                if len(t) < len(ans) or len(t) == len(ans) and t < ans:
                    ans = t
        return ans

