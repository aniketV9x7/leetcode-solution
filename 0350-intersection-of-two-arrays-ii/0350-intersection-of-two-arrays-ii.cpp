class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> r;
        for (int x : nums1) m[x]++;
        for (int x : nums2) {
            if (m[x] > 0) {
                r.push_back(x);
                m[x]--;
            }
        }
        return r;
    }
};
