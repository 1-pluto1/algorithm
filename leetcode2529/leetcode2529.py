class Solution:
    def low_bound(self, nums, target):
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if (nums[mid] >= target):
                right = mid - 1
            else:
                left = mid + 1
        return left
    def maximumCount(self, nums: List[int]) -> int:
        pos = len(nums) - self.low_bound(nums, 1)
        neg = self.low_bound(nums, 0)
    
        return max(pos, neg)
