import heapq

class City :
    def __init__(self, id) :
        self.id = id
        self.edges = []

    def __lt__(self, other):
        return self.id < other.id
    def __le__(self, other):
        return self.id <= other.id

class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        def getReachableCitiesCount(city, distanceThreshold) :
            heap = [(0, city)]
            visited = set()

            while heap :
                distance, city = heapq.heappop(heap)
                if city in visited :
                    continue

                visited.add(city)
                for edge in city.edges :
                    totalDistance = distance + edge[0]
                    if totalDistance <= distanceThreshold :
                        heapq.heappush(heap, (totalDistance, edge[1]))

            return len(visited) - 1

        cities = [City(i) for i in range(n)]
        for edge in edges :
            cities[edge[0]].edges.append((edge[2], cities[edge[1]]))
            cities[edge[1]].edges.append((edge[2], cities[edge[0]]))
        
        minCount = n
        result = 0

        for i in range(n) :
            city = cities[i]
            count = getReachableCitiesCount(city, distanceThreshold)
            if count <= minCount :
                minCount = count
                result = i

        return result
        