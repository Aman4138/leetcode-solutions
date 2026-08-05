class Solution {
public:
    vector<int> remainingMethods(int n,int k,vector<vector<int>>& e){
        vector<vector<int>> g(n); vector<int> v(n);
        for(auto &x:e) g[x[0]].push_back(x[1]);
        auto dfs=[&](auto&& s,int u)->void{
            v[u]=1;
            for(int x:g[u]) if(!v[x]) s(s,x);
        };
        dfs(dfs,k);
        for(auto &x:e)
            if(!v[x[0]]&&v[x[1]]){
                vector<int> a(n);
                iota(a.begin(),a.end(),0);
                return a;
            }
        vector<int> a;
        for(int i=0;i<n;i++) if(!v[i]) a.push_back(i);
        return a;
    }
};