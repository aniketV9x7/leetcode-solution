class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> cnt(26, 0);
            int mx = 0, distinct = 0;
            for(int j = i; j < n; j++){
                int c = s[j] - 'a';
                if(cnt[c]++ == 0) distinct++;
                mx = max(mx, cnt[c]);
                if(mx * distinct == j - i + 1) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
