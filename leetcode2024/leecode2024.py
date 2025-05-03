from collections import Counter, defaultdict

class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        ans = 0
        left = 0
        cnt = defaultdict(int)
        for right in range(len(answerKey)):
            cnt[answerKey[right]] += 1
            while cnt["T"] > k and cnt["F"] > k:
                cnt[answerKey[left]] -= 1
                if cnt[answerKey[left]] == 0:
                    cnt.pop(answerKey[left])
                left += 1
            ans = max(ans, right - left + 1)
        return ans

