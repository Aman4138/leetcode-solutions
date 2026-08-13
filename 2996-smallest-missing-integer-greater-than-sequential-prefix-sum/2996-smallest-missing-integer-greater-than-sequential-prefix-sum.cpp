class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefix=nums[0], i, n=nums.size();
        if (n==1) return prefix+1;
        for(i=1; i<n; i++){
            if (nums[i]!=nums[i-1]+1)
            break;
            prefix+=nums[i];
        }
        bitset<51> seen=0;
        for (int j=0; j<n; j++){
            seen[nums[j]]=1;
        }
        while(prefix<=50 && seen[prefix])
            prefix++;
        return prefix;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();