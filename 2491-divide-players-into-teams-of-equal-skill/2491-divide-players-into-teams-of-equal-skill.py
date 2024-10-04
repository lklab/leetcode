class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n = len(skill)
        skill.sort()

        teamSkill = skill[0] + skill[n-1]
        result = 0

        for i in range(n // 2) :
            r = n - 1 - i
            if skill[i] + skill[r] != teamSkill :
                return -1
            result += skill[i] * skill[r]

        return result
