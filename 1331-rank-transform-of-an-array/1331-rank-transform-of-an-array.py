class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        value_to_rank = {}  # Dictionary to store value-to-rank mapping
        sorted_unique_numbers = sorted(list(set(arr)))  # Remove duplicates and sort unique elements
        
        # Assign ranks to sorted unique elements
        for index in range(len(sorted_unique_numbers)): 
            value_to_rank[sorted_unique_numbers[index]] = index + 1
          
        # Replace each element in the original array with its rank
        for index in range(len(arr)): 
            arr[index] = value_to_rank[arr[index]]
        
        return arr  # Return the updated array
        # n = len(arr)
        # if n == 0 :
        #     return []

        # idxs = list(range(n))
        # idxs.sort(key=lambda x : arr[x])

        # current = arr[idxs[0]]
        # rank = 1

        # for idx in idxs :
        #     value = arr[idx]
        #     if value != current :
        #         rank += 1
        #         current = value
        #     arr[idx] = rank

        # return arr
