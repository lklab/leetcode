class Solution:
    def fractionAddition(self, expression: str) -> str:
        numerators = []
        denominators = []

        s = 0
        for i, c in enumerate(expression[1:], 1) :
            if c == '/' :
                numerators.append(int(expression[s:i]))
                s = i + 1
            elif c in ['+', '-'] :
                denominators.append(int(expression[s:i]))
                s = i
        denominators.append(int(expression[s:len(expression)]))

        n = len(numerators)
        result_den = 2520
        for i in range(n) :
            numerators[i] *= result_den // denominators[i]
        result_num = sum(numerators)

        if result_num == 0 :
            return "0/1"

        sign = result_num > 0
        result_num = abs(result_num)
        dividers = [2, 3, 5, 7]

        while result_num > 1 :
            flag = False

            for divider in dividers :
                if result_num % divider == 0 and result_den % divider == 0 :
                    result_num //= divider
                    result_den //= divider
                    flag = True
                    break

            if not flag :
                break

        if not sign :
            result_num = -result_num

        return str(result_num) + "/" + str(result_den)
