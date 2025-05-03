class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        free = [startTime[0]] + [s - e for s, e in zip(startTime[1:], endTime)] + [eventTime - endTime[-1]]
        ans = s = 0
        for i, f in enumerate(free):
            s += f
            if i < k:
                continue
            ans = max(ans, s)
            s -= free[i - k]
        return ans
    