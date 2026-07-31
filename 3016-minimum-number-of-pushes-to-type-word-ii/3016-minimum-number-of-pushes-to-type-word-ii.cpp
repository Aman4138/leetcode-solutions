class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char x : word) {
            freq[x - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<>());

        int total = 0;

        for (int i = 0; i < freq.size(); i++) {
            int pushes = (i / 8) + 1;
            total += (freq[i] * pushes);
        }

        return total;
    }
};