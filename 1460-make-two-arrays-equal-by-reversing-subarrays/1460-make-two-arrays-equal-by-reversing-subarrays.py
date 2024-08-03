class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        def getArrDict(arr) :
            arrDict = {}
            for n in arr :
                if n not in arrDict :
                    arrDict[n] = 1
                else :
                    arrDict[n] += 1
            return arrDict

        targetDict = getArrDict(target)
        arrDict = getArrDict(arr)

        for key, val in targetDict.items() :
            try :
                if arrDict[key] != val :
                    return False
            except KeyError :
                return False

        return True
