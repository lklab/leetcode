class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        values = []

        for i in range(len(nums)) :
            target = nums[i]
            mapped = 0
            digit = 1

            if target == 0 :
                mapped = mapping[0]

            while target > 0 :
                mapped += mapping[target % 10] * digit

                target //= 10
                digit *= 10

            values.append((mapped, i, nums[i]))

        values.sort(key=lambda x: (x[0], x[1]))
        return [value[2] for value in values]
