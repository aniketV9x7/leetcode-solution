class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string t;
        for (auto& w : words) {
            t += w;
            if (t == s) return true;
            if (t.size() > s.size()) return false;
        }
        return false;
    }
};
