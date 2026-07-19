class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;

        // for(int i = 0; i < s.length(); i++) {
        //     if(s[i] == '(') {
        //         if(count = 0) {
        //             ans = ans + s[i];
        //         }
        //         count++;
        //     }
        //     else {
        //         count--;

        //         if(count = 0) {
        //             ans = ans + s[i];
        //         }
        //     }
        // }
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                if(count != 0) {
                    ans = ans + s[i];
                }
                count++;
            }
            else {
                count--;

                if(count != 0) {
                    ans = ans + s[i];
                }
            }
        }
        return ans ;
    }
};