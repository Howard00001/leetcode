// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int st=1,ed=n,mid;
        while(st!=ed){
            mid = st+(ed-st)/2;
            if(isBadVersion(mid)){
                ed = mid;
            }else{
                st = mid+1;
            }
        }
        return st;
    }
};