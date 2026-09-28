class Solution {
public:

    string getPermutation(int n, int k) {

        vector<int> nums;
        int fact = 1;

        // Store numbers from 1 to n
        // and calculate (n - 1)!
        for (int i = 1; i < n; i++) {
            fact *= i;
            nums.push_back(i);
        }

        nums.push_back(n);

        // Convert k to 0-based indexing
        k--;

        string ans = "";

        while (true) {

            // Find the index of the required number
            int index = k / fact;

            ans += to_string(nums[index]);

            // Remove the selected number
            nums.erase(nums.begin() + index);

            // All numbers are used
            if (nums.empty())
                break;

            // Find the position within the current block
            k = k % fact;

            // Calculate factorial for remaining elements
            fact = fact / nums.size();
        }

        return ans;
    }
};