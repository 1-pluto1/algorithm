from collections import Counter
class Solution:
    def balancedString(self, s: str) -> int:
        m = len(s) // 4
        cnt = Counter(s)
        if len(cnt) == 4 and min(cnt.values()) == m:
            return 0
        ans, left = len(s) + 1, 0
        for right in range(len(s)):
            cnt[s[right]] -= 1
            while max(cnt.values()) <= m:
                ans = min(ans, right - left + 1)
                cnt[s[left]] += 1
                left += 1
        return ans
