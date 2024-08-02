class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)

        # count ones
        oneCount = 0
        for num in nums :
            if num == 1 :
                oneCount += 1

        # count zeros in [0 ~ oneCount)
        zeroCount = 0
        for i in range(oneCount) :
            if nums[i] == 0 :
                zeroCount += 1

        # find min zeros in [s+1, e]
        min = zeroCount
        for i in range(n) :
            s = i
            e = (i + oneCount) % n

            if nums[s] == 0 :
                zeroCount -= 1
            if nums[e] == 0 :
                zeroCount += 1

            if min > zeroCount :
                min = zeroCount

        return min
