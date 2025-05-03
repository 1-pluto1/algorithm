from collections import Counter, defaultdict

class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        ans = 0
        left = 0
        cnt = defaultdict(int)
        for right in range(len(nums)):
            # _sum += nums[right]
            cnt[nums[right]] += 1
            while cnt[nums[right]] > k:
                # _sum -= nums[left]
                cnt[nums[left]] -= 1
                if cnt[nums[left]] == 0:
                    cnt.pop(nums[left])
                left += 1
            ans = max(ans, right - left + 1)
        return ans

