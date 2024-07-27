import heapq

class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        costDict = {}
        minDict = {}

        for i in range(len(original)) :
            o = original[i]
            t = changed[i]
            c = cost[i]

            if o not in costDict :
                costDict[o] = []
            costDict[o].append((c, t))

        def getMinimumCost(costDict, minDict, o, t) :
            edge = (o, t)
            if edge in minDict :
                return minDict[edge]

            if o not in costDict :
                return -1

            heap = [(0, o)]
            visited = set()

            while heap :
                cost, node = heapq.heappop(heap)

                if node in visited :
                    continue
                visited.add(node)

                if node == t :
                    minDict[(o, t)] = cost
                    return cost

                if node not in costDict :
                    continue

                for edge in costDict[node] :
                    heapq.heappush(heap, (cost + edge[0], edge[1]))

            return -1

        totalCost = 0

        for i in range(len(source)) :
            if source[i] == target[i] :
                continue

            cost = getMinimumCost(costDict, minDict, source[i], target[i])
            if cost == -1 :
                return -1
            totalCost += cost

        return totalCost
