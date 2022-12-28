class Solution:
    def checkValidString(self, s: str) -> bool:
        lmin, lmax = 0, 0
        for c in s:
            if c=='(':
                lmin = lmin+1
                lmax = lmax+1
            elif c==')':
                lmin = lmin-1
                lmax = lmax-1
            else:
                lmin = lmin-1
                lmax = lmax+1
            
            if lmin <0:
                lmin=0
            if lmax <0:
                return False
            
        return lmin <= 0