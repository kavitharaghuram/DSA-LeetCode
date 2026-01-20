class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for(const auto& time: times){
            edges[time[0]].push_back({time[1], time[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, k}); //w, v
        unordered_set<int>visited;
        int t=0;
        while(!minHeap.empty()){
            auto curr= minHeap.top();
            minHeap.pop();
            int w1= curr.first;
            int v1= curr.second;
            if(visited.count(v1))continue;
            visited.insert(v1);
            t= max(t, w1);
            if(edges.count(v1)){
                for(const auto& next: edges[v1]){
                    int v2= next.first;
                    int w2= next.second;
                    if(!visited.count(v2)){
                        minHeap.push({w1+w2, v2});
                    }
                }
            }
        }
        return visited.size()==n? t: -1;
    }
};