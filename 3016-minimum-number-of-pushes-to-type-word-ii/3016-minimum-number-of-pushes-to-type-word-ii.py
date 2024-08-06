from collections import Counter

class Solution:
    def minimumPushes(self, word) :
        counter = Counter(word)

        result = 0
        pushes = 1
        button = 2
        for _, count in counter.most_common() :
            result += count * pushes

            button += 1
            if button > 9 :
                pushes += 1
                button = 2

        return result
