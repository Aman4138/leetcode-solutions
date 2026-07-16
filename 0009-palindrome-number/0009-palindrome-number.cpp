class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)){
            return false;
        }
        int halfrev = 0;

        while(halfrev < x){
            halfrev = halfrev * 10 + (x % 10);
            x /= 10;
        }

        return halfrev == x || halfrev / 10 == x;
    }
};