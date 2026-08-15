class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorValue = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            xorValue ^= x;

            if (x != 0) {
                hasNonZero = true;
            }
        }

        if (xorValue != 0) {
            return nums.size();
        }

        if (hasNonZero) {
            return nums.size() - 1;
        }

        return 0;
    }
};