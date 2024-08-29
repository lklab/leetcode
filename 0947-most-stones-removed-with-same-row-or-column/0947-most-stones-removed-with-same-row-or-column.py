class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        n = len(stones)
        cGroups = {}
        rGroups = {}
        groupId = 0
        groupCount = 0

        for stone in stones :
            c = stone[0]
            r = stone[1]
            isC = c in cGroups
            isR = r in rGroups

            if not isC and not isR :
                groupCount += 1
                group = [groupId, None]
                groupId += 1
                cGroups[c] = group
                rGroups[r] = group

            elif isC and not isR :
                rGroups[r] = cGroups[c]
            elif not isC and isR :
                cGroups[c] = rGroups[r]

            else :
                cRoot = cGroups[c]
                rRoot = rGroups[r]

                while cRoot[1] :
                    cRoot = cRoot[1]
                while rRoot[1] :
                    rRoot = rRoot[1]

                if cRoot[0] != rRoot[0] :
                    groupCount -= 1
                    rootGroup = [groupId, None]
                    groupId += 1
                    cRoot[1] = rootGroup
                    rRoot[1] = rootGroup

        return n - groupCount
