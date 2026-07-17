class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int a = n * n;
        int b = n * (n + 1);
        return std::gcd(a,b);
    }
};