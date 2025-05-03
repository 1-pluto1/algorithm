from collections import Counter
class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        cnt = Counter(nums[: k - 1])
        _sum = sum(nums[: k - 1])
        for _in, out in zip(nums[k - 1:], nums):
            cnt[_in] += 1
            _sum += _in
            if len(cnt) == k:
                ans = max(ans, _sum)
            cnt[out] -= 1
            if cnt[out] == 0:
                del cnt[out]
            _sum -= out
        return ans