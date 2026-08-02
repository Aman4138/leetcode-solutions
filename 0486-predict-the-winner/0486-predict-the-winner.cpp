class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        if (n % 2 == 0) return true; 
        
        vector<int> dp(nums);
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        return dp[n - 1] >= 0;
    }
};