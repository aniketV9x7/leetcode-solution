class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        array<int,26> cnt{};
        for (char c : s) cnt[c - 'a']++;
        for (char c : t) {
            if (--cnt[c - 'a'] < 0) return false;
        }
        return true;
    }
};