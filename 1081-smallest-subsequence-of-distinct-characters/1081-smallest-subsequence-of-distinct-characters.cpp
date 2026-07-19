class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> last(26);
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<bool> taken(26, false);
        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if (taken[ch - 'a']) {
                continue;
            }

            while (!ans.empty() &&
                   ans.back() > ch &&
                   last[ans.back() - 'a'] > i) {

                taken[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans += ch;
            taken[ch - 'a'] = true;
        }

        return ans;
    }
};