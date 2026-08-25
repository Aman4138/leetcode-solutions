class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> present(nums.begin(), nums.end());

        int multiple = k;

        while (present.count(multiple)) {
            multiple += k;
        }

        return multiple;
    }
};