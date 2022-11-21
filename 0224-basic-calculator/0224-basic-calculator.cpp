class Solution {
public:
    // int calculate(string s) {
    //     stack<pair<int,int>> st;
    //     int num=0;
    //     int sign=1;
    //     for(int i=0;i<s.size();i++){
    //         if(s[i]==' ') continue;
    //         if(isdigit(s[i])){
    //             int i0=s[i]-'0';
    //             while(i+1<s.size() && isdigit(s[i+1])) {
    //                 i0=i0*10+s[i+1]-'0';
    //                 i++;
    //             }
    //             num += i0*sign;
    //             sign = 1;
    //         }
    //         if(s[i]=='-') sign = -1;
    //         if(s[i]=='+') sign = 1;
    //         if(s[i]=='('){
    //             st.push({num, sign});
    //             num = 0;
    //             sign = 1;
    //         }
    //         if(s[i]==')'){
    //             int a = st.top().first;
    //             sign = st.top().second;
    //             st.pop();
    //             num = a+num*sign;
    //         }
    //     }
    //     return num;
    // }
    int calculate(string s) {
        int size = s.size();

        int i = 0, ans = 0;

        char prevOperation = '+';
        stack<pair<int, char>> st;
        while(i < size){
            // If string having space
            if(s[i] == ' '){
                i++;
                continue;
            }

            // Check if string having digit
            int num = 0;
            while(i < size && isdigit(s[i])){
                num = 10 * num + (s[i] - '0');
                i++;
            } 

            // Which operator is consist by string
            if(prevOperation == '+')
                ans += num;
            else if(prevOperation == '-')
                ans += -1 * num;

            // Solve the ()
            if(s[i] == '('){
                st.push({ans, prevOperation});
                ans = 0;
                prevOperation = '+';
                i++;
                continue;
            }
            else if(s[i] == ')'){
                auto top = st.top();
                st.pop();
                if(top.second == '-')
                    ans = -1 * ans + top.first;
                else
                    ans = ans + top.first;
            }

            prevOperation = s[i];
            i++;          
        }
        return ans;
    }
};