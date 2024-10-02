class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        n = len(arr)
        if n == 0 :
            return []

        idxs = list(range(n))
        idxs.sort(key=lambda x : arr[x])

        current = arr[idxs[0]]
        rank = 1

        for idx in idxs :
            value = arr[idx]
            if value != current :
                rank += 1
                current = value
            arr[idx] = rank

        return arr
