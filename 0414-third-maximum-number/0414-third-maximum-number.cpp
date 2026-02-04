class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long a = LLONG_MIN, b = LLONG_MIN, c = LLONG_MIN;
        for (int x : nums) {
            if (x == a || x == b || x == c) continue;
            if (x > a) {
                c = b;
                b = a;
                a = x;
            } else if (x > b) {
                c = b;
                b = x;
            } else if (x > c) {
                c = x;
            }
        }
        return c == LLONG_MIN ? a : c;
    }
};
