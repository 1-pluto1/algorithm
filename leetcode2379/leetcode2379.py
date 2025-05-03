class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        ans = float('inf')
        cnt = 0
        for i, c in enumerate(blocks):
            if c == "W":
                cnt += 1
            if i < k - 1:
                continue
            ans = min(cnt, ans)

            if blocks[i - k + 1] == 'W':
                cnt -= 1
        return ans
    

# 灵神解法
class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        ans = cnt_w = blocks[:k].count('W')
        for in_, out in zip(blocks[k:], blocks):
            cnt_w += (in_ == 'W') - (out == 'W')
            ans = min(ans, cnt_w)
        return ans

