class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int a=nums[0];
        int b=nums[n-1];
        while(a&&b){
            a>=b?a%=b:b%=a;
        }
        return  a==0?b:a;
        
    }
};