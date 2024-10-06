class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        words1 = sentence1.split()
        words2 = sentence2.split()
        n1 = len(words1)
        n2 = len(words2)

        s = 0
        minn = min(n1, n2)
        while s < minn and words1[s] == words2[s] :
            s += 1
        if s == minn :
            return True

        s -= 1
        e1 = n1 - 1
        e2 = n2 - 1
        while e1 >= 0 and e2 >= 0 and e1 > s and e2 > s and words1[e1] == words2[e2] :
            e1 -= 1
            e2 -= 1
        if e1 == -1 or e2 == -1 :
            return True

        if s == e1 or s == e2 :
            return True

        return False
