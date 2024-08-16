class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        my = {5: 0, 10: 0, 20: 0}
        kinds = [20, 10, 5]

        for bill in bills :
            change = bill - 5

            for kind in kinds :
                while change >= kind and my[kind] > 0 :
                    change -= kind
                    my[kind] -= 1

            if change == 0 :
                my[bill] += 1
            else :
                return False

        return True
