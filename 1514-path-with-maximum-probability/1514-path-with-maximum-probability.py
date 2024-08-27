class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        graph = {}
        for edge, prob in zip(edges, succProb) :
            n0 = edge[0]
            n1 = edge[1]

            if n0 not in graph :
                graph[n0] = []
            if n1 not in graph :
                graph[n1] = []

            graph[n0].append((prob, n1))
            graph[n1].append((prob, n0))

        heap = []
        heapq.heappush(heap, (-1.0, start_node))
        visited = set()

        while heap :
            prob, node = heapq.heappop(heap)
            prob = -prob

            if node == end_node :
                return prob

            if node in visited :
                continue
            visited.add(node)

            if node not in graph :
                continue

            for edge in graph[node] :
                heapq.heappush(heap, (-(prob * edge[0]), edge[1]))

        return 0.0
