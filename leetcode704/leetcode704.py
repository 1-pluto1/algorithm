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
    def search(self, nums: List[int], target: int) -> int:
        ans = self.low_bound(nums, target)
        if ans == len(nums): return -1
        if nums[ans] != target: return -1
        return ans
