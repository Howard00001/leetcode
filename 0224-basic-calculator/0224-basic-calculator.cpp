class Solution {
public:
    int calculate(string s) {
        stack<pair<int,int>> st;
        int num=0;
        int sign=1;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') continue;
            if(isdigit(s[i])){
                int i0=i;
                while(i+1<s.size() && isdigit(s[i+1])) i++;
                num += stoi(s.substr(i0,i-i0+1))*sign;
                sign = 1;
            }
            if(s[i]=='-') sign = -1;
            if(s[i]=='+') sign = 1;
            if(s[i]=='('){
                st.push({num, sign});
                num = 0;
                sign = 1;
            }
            if(s[i]==')'){
                int a = st.top().first;
                sign = st.top().second;
                st.pop();
                num = a+num*sign;
            }
        }
        return num;
    }
};