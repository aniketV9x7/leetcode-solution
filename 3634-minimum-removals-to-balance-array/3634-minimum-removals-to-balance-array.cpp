class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, maxLen = 0, n = nums.size();
        for (int right = 0; right < n; ++right) {
            while ((long long)nums[left] * k < nums[right]) left++;
            maxLen = max(maxLen, right - left + 1);
        }
        return n - maxLen;
    }
};
