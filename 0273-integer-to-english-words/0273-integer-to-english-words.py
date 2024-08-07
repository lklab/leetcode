class Solution:
    def numberToWords(self, num: int) -> str:
        oneWords = ['Zero', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine']
        teenWords = ['Ten', 'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen']
        tenWords = ['', 'Ten', 'Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']
        hundredWord = 'Hundred'
        thousandWords = ['Thousand', 'Million', 'Billion']

        def toTenWords(num) :
            if num < 10 :
                return [oneWords[num]]
            if num < 20 :
                return [teenWords[num - 10]]

            one = num % 10
            if one == 0 :
                return [tenWords[num // 10]]
            else :
                return [tenWords[num // 10], oneWords[one]]

        def toHundredWords(num) :
            words = []

            if num >= 100 :
                words.append(oneWords[num // 100])
                words.append(hundredWord)

                ten = num % 100
                if ten == 0 :
                    return words
                else :
                    return words + toTenWords(ten)
            else :
                return toTenWords(num)

        if num == 0 :
            return oneWords[0]

        words = []
        idx = -1

        while num > 0 :
            hundread = num % 1000

            if hundread != 0 :
                hundreadWords = toHundredWords(hundread)
                if idx == -1 :
                    words = hundreadWords
                else :
                    hundreadWords.append(thousandWords[idx])
                    words = hundreadWords + words

            num //= 1000
            idx += 1

        return ' '.join(words)
