class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        left = 0
        ans = 1
        cost = 0
        nums.sort()
        for right in range(1, len(nums)):
            cost += ((nums[right] - nums[right - 1]) * (right - left))
            while cost > k:
                cost -= (nums[right] - nums[left])
                left += 1
            ans = max(ans, right - left + 1)
        return ans