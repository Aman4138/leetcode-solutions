class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int totalOnes = 0;

        // Count total ones
        for(char c : s){
            if(c == '1')
                totalOnes++;
        }

        // Store groups
        vector<pair<char,int>> groups;

        int i = 0;
        int n = s.size();

        while(i < n){

            char ch = s[i];
            int len = 0;

            while(i < n && s[i] == ch){
                len++;
                i++;
            }

            groups.push_back({ch, len});
        }

        int answer = totalOnes;

        // Check every 0-1-0 pattern
        for(int i = 1; i + 1 < groups.size(); i++){

            if(groups[i].first == '1' &&
               groups[i-1].first == '0' &&
               groups[i+1].first == '0'){

                int gain = groups[i-1].second + groups[i+1].second;

                answer = max(answer, totalOnes + gain);
            }
        }

        return answer;
    }
};