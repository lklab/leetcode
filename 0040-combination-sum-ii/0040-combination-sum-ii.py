class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        n = len(candidates)
        candidates.sort()

        def getCombinations(start, target) :
            combinations = []
            current = None

            for i in range(start, n) :
                if candidates[i] == current :
                    continue
                elif candidates[i] == target :
                    combinations.append([candidates[i]])
                    break
                elif candidates[i] > target :
                    break
                else :
                    current = candidates[i]
                    subs = getCombinations(i + 1, target - current)
                    for sub in subs :
                        combinations.append([current] + sub)

            return combinations

        return getCombinations(0, target)
