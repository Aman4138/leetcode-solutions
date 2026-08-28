class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        // Check palindrome possible or not
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

        // Make left half
        vector<int> half(26);

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        int m = n / 2;
        string left = "";

        // Try to make smallest possible answer
        for (int pos = 0; pos < m; pos++) {

            bool ok = false;

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                left += char('a' + c);
                half[c]--;

                // Make the largest possible palindrome
                string temp = left;

                for (int x = 25; x >= 0; x--) {
                    for (int k = 0; k < half[x]; k++)
                        temp += char('a' + x);
                }

                string pal = temp;

                if (n % 2)
                    pal += mid;

                for (int i = m - 1; i >= 0; i--)
                    pal += temp[i];

                if (pal > target) {
                    ok = true;
                    break;
                }

                left.pop_back();
                half[c]++;
            }

            if (!ok)
                return "";
        }

        // Build answer
        string ans = left;

        if (n % 2)
            ans += mid;

        for (int i = m - 1; i >= 0; i--)
            ans += left[i];

        return ans > target ? ans : "";
    }
};