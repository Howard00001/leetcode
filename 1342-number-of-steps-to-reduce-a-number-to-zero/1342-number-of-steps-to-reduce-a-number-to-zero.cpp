class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0;
        while(num!=0){
            if(num&1){
                res++;
                num--;
            }else{
                num = num>>1;
                res++;
            }
            
        }
        return res;
    }
};