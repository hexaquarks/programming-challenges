class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        my_dict_1, my_dict_2 = {}, {}

        for l, r in zip(s, t):
            if l in my_dict_1:
                if my_dict_1[l] != r:
                    return False
            else:
                my_dict_1[l] = r
            
            if r in my_dict_2:
                if my_dict_2[r] != l:
                    return False
            else:
                my_dict_2[r] = l
                
        return True
