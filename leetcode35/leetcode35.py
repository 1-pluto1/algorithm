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
    def searchInsert(self, nums: List[int], target: int) -> int:
        return self.low_bound(nums, target)
