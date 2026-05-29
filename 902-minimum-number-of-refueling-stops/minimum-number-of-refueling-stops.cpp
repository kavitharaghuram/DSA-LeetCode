class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>availableFuel;
        stations.push_back({target, 0});
        long long maxreach= startFuel;
        int stops=0;
        for(auto &station: stations){
            int statPos= station[0];
            int statFuel= station[1];
            while(maxreach < statPos){
                if(availableFuel.empty())return -1;
                maxreach += availableFuel.top();
                availableFuel.pop();
                stops++;
            }
            availableFuel.push(statFuel);
        }
        return stops;
    }
};