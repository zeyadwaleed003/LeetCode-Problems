class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int l = 0, r = 0, ans = 1, n = s.size(), ok = 1;
    char ch = 'a';

    if (n == 0 || n == 1) {
        return n;
    }

    map<char,int>frq;
    frq[s[0]]++;

    while (l <= r && r < n) {
        if (ok == 1) {
            ans = max(ans, r - l + 1);
            r++;
            if (r < n) {
                frq[s[r]]++;
                if (frq[s[r]] > 1) {
                    ok = 0;
                    ch = s[r];
                }
            } else {
                break;
            }
        } else {
            frq[s[l]]--;
            l++;
            if (frq[ch] < 2) {
                ok = 1;
            }
        }
    }

    return ans;
}
};