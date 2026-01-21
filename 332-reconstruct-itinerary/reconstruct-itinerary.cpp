class Solution {
public:
    unordered_map<string, multiset<string>> adj;
    vector<string>res;

    void dfs(const string& src){
        while(!adj[src].empty()){
            auto it= adj[src].begin();
            string next= *it;
            adj[src].erase(it);
            dfs(next);
        }
        res.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& ticket: tickets){
            adj[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
 
};