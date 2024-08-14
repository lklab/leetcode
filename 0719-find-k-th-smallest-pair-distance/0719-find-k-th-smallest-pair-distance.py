class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()

        def countPairsLE(val) :
            i = 0
            j = 1
            count = 0

            while j < n :
                if nums[j] - nums[i] > val :
                    count += j - i - 1
                    i += 1
                else :
                    j += 1

            remains = j - i
            return count + remains * (remains - 1) // 2

        l = 0
        r = nums[n - 1] - nums[0]

        while r > l :
            m = (r + l) // 2
            count = countPairsLE(m)

            if count >= k :
                r = m
            else :
                l = m + 1

        return r
