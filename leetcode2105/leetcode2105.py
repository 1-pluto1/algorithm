class Solution:
    def minimumRefill(self, plants: List[int], capacityA: int, capacityB: int) -> int:
        ans = 0
        a, b = capacityA, capacityB
        left, right = 0, len(plants) - 1
        while left < right:
            if a < plants[left]:
                ans += 1
                a = capacityA
            a -= plants[left]
            left += 1

            if b < plants[right]:
                ans += 1
                b = capacityB
            b -= plants[right]
            right -= 1
        if left == right and max(a, b) < plants[left]:
            ans += 1
        return ans
