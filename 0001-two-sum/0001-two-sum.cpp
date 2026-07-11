class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int required = target - nums[i];

            if (mp.find(required) != mp.end()) {
                return {mp[required], i};
            }

            mp[nums[i]] = i;
        }
        return {};
    }
};