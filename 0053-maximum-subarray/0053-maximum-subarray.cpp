int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string s; getline(cin, s); cout << '\n') {
        int ans = INT_MIN, sum = 0;
        for (int _i = 1, _n = s.length(); _i < _n; ++_i) {
            bool _neg = false;
            if (s[_i] == '-') ++_i, _neg = true;
            int v = s[_i++] & 15;
            while ((s[_i] & 15) < 10) v = v * 10 + (s[_i++] & 15);
            if (_neg) v = -v;
            sum = max(sum + v, v);
            ans = max(ans, sum);
        }
        cout << ans;
    }
    exit(0);
    return 0;
}();

class Solution {
public:
    int maxSubArray(vector<int>& nums) {return 0;}
};