# class Solution:
#     def minSubArrayLen(self, target: int, nums: List[int]) -> int:
#         result = float('inf')
#         left = 0
#         right = 0
#         sum = 0
#         subLength = 0
#         while right < len(nums):
#             sum += nums[right]
#             while sum >= target:
#                 subLength = right - left + 1
#                 result = min(result, subLength)
#                 sum -= nums[left]
#                 left += 1
#             right += 1
#         return result if result != float('inf') else 0
    
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ans = float('inf')
        left = 0
        right = 0
        sum = 0
        for right in range(len(nums)):
            sum += nums[right]
            while sum >= target:
                ans = min(ans, right - left + 1)
                sum -= nums[left]
                left += 1
            right += 1
        return ans if ans != float('inf') else 0