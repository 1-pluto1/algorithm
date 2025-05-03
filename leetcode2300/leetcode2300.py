from bisect import bisect_right


class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        m = len(potions)
        success -= 1
        return [m - bisect_right(potions, success // x) for x in spells]

