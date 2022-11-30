class Solution {
public:
    int racecar(int target) {
        int res=0;
        queue<pair<int,int>> Q;
        Q.push({0,1});
        while(!Q.empty()){
            int sz = Q.size();
            while(sz--){
                int pos = Q.front().first;
                int speed = Q.front().second;
                Q.pop();
                //avoid overflow
                if (abs(pos) > 2 * target) continue;
                if(pos==target) return res;
                Q.push({pos+speed, speed*2});
                //avoid wrong direction
                if((pos+speed>target && speed>0) || (pos+speed<target && speed<0))
                    Q.push({pos, (speed>0)?-1:1});
            }
            res++;
        }
        return -1;
    }
};