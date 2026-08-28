class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // Count characters
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check whether palindrome is possible
        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                middle = 'a' + i;
            }
        }

        if (odd > 1) {
            return "";
        }

        // Characters needed for left half
        vector<int> half(26);

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        int halfLen = n / 2;
        string left = "";

        // Build left half
        for (int pos = 0; pos < halfLen; pos++) {

            bool found = false;

            // Try smallest character first
            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                // Take this character
                left += char('a' + c);
                half[c]--;

                // Make the biggest possible remaining half
                string temp = left;

                for (int x = 25; x >= 0; x--) {
                    temp += string(half[x], char('a' + x));
                }

                // Make palindrome
                string pal = temp;

                if (n % 2 == 1) {
                    pal += middle;
                }

                // Add reverse of left half
                for (int i = halfLen - 1; i >= 0; i--) {
                    pal += temp[i];
                }

                // If it is greater than target,
                // this character is possible
                if (pal > target) {
                    found = true;
                    break;
                }

                // Otherwise undo
                left.pop_back();
                half[c]++;
            }

            // No character can make answer greater
            if (!found) {
                return "";
            }
        }

        // Create final answer
        string ans = left;

        if (n % 2 == 1) {
            ans += middle;
        }

        for (int i = halfLen - 1; i >= 0; i--) {
            ans += left[i];
        }

        return ans > target ? ans : "";
    }
};