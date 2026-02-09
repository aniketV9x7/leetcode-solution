class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), parent(n, -1);
        int mx = 1, idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > mx) {
                mx = dp[i];
                idx = i;
            }
        }
        vector<int> res;
        while (idx != -1) {
            res.push_back(nums[idx]);
            idx = parent[idx];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
