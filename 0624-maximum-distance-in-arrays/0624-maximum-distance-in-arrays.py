class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        mins = [(10001, -1), (10001, -1)]
        maxs = [(-10001, -1), (-10001, -1)]

        def addMin(val) :
            if val[0] <= mins[0][0] :
                (val, mins[0]) = (mins[0], val)
            if val[0] <= mins[1][0] :
                mins[1] = val
        
        def addMax(val) :
            if val[0] >= maxs[0][0] :
                (val, maxs[0]) = (maxs[0], val)
            if val[0] >= maxs[1][0] :
                maxs[1] = val

        for idx, array in enumerate(arrays) :
            n = len(array)
            addMin((array[0], idx))
            addMax((array[n-1], idx))

        if mins[0][1] != maxs[0][1] :
            return maxs[0][0] - mins[0][0]
        else :
            return max(maxs[1][0] - mins[0][0], maxs[0][0] - mins[1][0])
