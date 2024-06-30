class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        tokens = text.split()
        ans = []
        for i, token in enumerate(tokens):
            if token == first:
                if i + 2 >= len(tokens):
                    return ans
                else:
                    if tokens[i + 1] == second:
                        ans.append(tokens[i + 2])
                        i += 2

        return ans
