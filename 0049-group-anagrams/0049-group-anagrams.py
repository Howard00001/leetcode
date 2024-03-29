class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        table = {};
        for str in strs:
            tmp = ''.join(sorted(str))
            # table.setdefault(tmp, []).append(str)
            if tmp not in table:
                table[tmp] = [str]
            else:
                table[tmp].append(str)
        result = []
        for key in table:
            result.append(table[key])
        return result