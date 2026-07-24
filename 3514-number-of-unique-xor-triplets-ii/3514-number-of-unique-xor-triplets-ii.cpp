class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int M=2048;
        vector<vector<int>> dp(4,vector<int>(M));
        dp[0][0]=1;
        for(int t=0;t<3;t++){
            for(int x=0;x<M;x++){
                if(!dp[t][x]) continue;
                for(int v:nums) dp[t+1][x^v]=1;
            }
        }
        int ans=0;
        for(int x=0;x<M;x++){
            if(dp[3][x]) ans++;
        }
        return ans;
    }
};