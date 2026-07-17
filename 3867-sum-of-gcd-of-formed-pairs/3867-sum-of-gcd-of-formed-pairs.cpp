class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long>pref;
        long long maxi = 0;
        for(int x:nums){
            if(x > maxi){
                maxi = x;
            }
            pref.push_back(gcd(maxi,x));
        }
        sort(pref.begin(),pref.end());

        int n = pref.size();
        int i = 0;
        int j = n-1;
        long long ans = 0;
        while(i<j){
            ans += gcd(pref[i] , pref[j]);
            i++;
            j--;
        }
        return ans;
    }
};