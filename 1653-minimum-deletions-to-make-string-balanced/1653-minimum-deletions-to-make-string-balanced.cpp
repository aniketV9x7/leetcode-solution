class Solution {
public:
    int minimumDeletions(string s) {
        int b = 0, res = 0;
        for (char c : s) {
            if (c == 'b') {
                b++;
            } else {
                res = min(res + 1, b);
            }
        }
        return res;
    }
};
