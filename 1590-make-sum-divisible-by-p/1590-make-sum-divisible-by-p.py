class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        n = len(nums)
        prefixRemains = [0] * n
        remainMap = {}

        remain = nums[0] % p
        prefixRemains[0] = remain
        remainMap[remain] = [0]

        minSize = n

        for i, num in enumerate(nums[1:], 1) :
            remain = (prefixRemains[i-1] + num) % p
            prefixRemains[i] = remain

            if remain not in remainMap :
                remainMap[remain] = [i]
            else :
                remainMap[remain].append(i)

        remainder = prefixRemains[n-1]

        if remainder == 0 :
            return 0

        for i, prefixRemain in enumerate(prefixRemains) :
            target = prefixRemain - remainder
            size = n

            if target < 0 :
                target += p
            elif target == 0 :
                size = i + 1

            candidates = remainMap.get(target)
            if candidates != None :
                targetIdx = bisect.bisect_left(candidates, i) - 1
                if targetIdx >= 0 :
                    size = i - candidates[targetIdx]

            if size < minSize :
                minSize = size

        if minSize == n :
            return -1
        return minSize
