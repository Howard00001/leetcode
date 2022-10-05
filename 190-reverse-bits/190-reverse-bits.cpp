class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        uint32_t curr = 1;
        for(int i=0;i<31;i++){
            curr *=2;
        }
        for(int i=0;i<32;i++){
            res += curr*(n%2);
            n = n/2;
            curr /=2;
        }
        return res;
    }
};